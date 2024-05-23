#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/irq.h"


// screen stuff
#include "pico/binary_info.h"
#include "font.h"
#include "ssd1306.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hardware/i2c.h"

#define UART_ID uart0
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY    UART_PARITY_NONE

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

static int chars_rxed = 0;

void drawChar(int x, int y, char letter) {
    int i, j;
    for(i = 0;  i < 5; i++) {
        char c =  ASCII[letter-32 ][i]; 
        for(j = 0; j < 8; j++) {
            char bit = (c>>j)&0b1;

            if (bit == 0b1){
                ssd1306_drawPixel(x + i, y + j, 1);
            }
            else {
                ssd1306_drawPixel(x + i, y + j, 0); 
            }
        }
    }
}

void drawMessage(int x, int y, const char *m) {
    int i = 0;
    while(m[i] != '\0') {
        drawChar(x, y, m[i]);
        x += 5;
        i++;
    }
    ssd1306_update();
}

volatile int i = 0;
volatile char m[50];

// RX interrupt handler
void on_uart_rx() {
    while (uart_is_readable(UART_ID)) {
        uint8_t ch = uart_getc(UART_ID);
        
        if (ch == '\r') {
            m[i] = '\0';
            drawMessage(0, 0, (const char *)m);
            ssd1306_clear();
            i = 0;
        }
        else {
            if (i < sizeof(m) - 1) {
                m[i] = ch;
                i++;
            }
        }
        
        // Can we send it back?
        if (uart_is_writable(UART_ID)) {
            // Change it slightly first!
            ch;
            uart_putc(UART_ID, ch);
        }
        chars_rxed++;
    }
}

int main() {
    stdio_init_all();
    
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    
    ssd1306_setup();

    // Set up our UART with a basic baud rate.
    uart_init(UART_ID, 2400);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Actually, we want a different speed
    // The call will return the actual baud rate selected, which will be as close as
    // possible to that requested
    int __unused actual = uart_set_baudrate(UART_ID, BAUD_RATE);

    // Set UART flow control CTS/RTS, we don't want these, so turn them off
    uart_set_hw_flow(UART_ID, false, false);

    // Set our data format
    uart_set_format(UART_ID, DATA_BITS, STOP_BITS, PARITY);

    // Turn off FIFO's - we want to do this character by character
    uart_set_fifo_enabled(UART_ID, false);

    // Set up a RX interrupt
    // We need to set up the handler first
    // Select correct interrupt for the UART we are using
    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;

    // And set up and enable the interrupt handlers
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);

    // Now enable the UART to send interrupts - RX only
    uart_set_irq_enables(UART_ID, true, false);

    // OK, all set up.
    // Lets send a basic string out, and then run a loop and wait for RX interrupts
    // The handler will count them, but also reflect the incoming data back with a slight change!
    uart_puts(UART_ID, "\nHello, uart interrupts\n");

    while (1)
        tight_loop_contents(); // it didn't work without this so i grabbed this from the example too
}

