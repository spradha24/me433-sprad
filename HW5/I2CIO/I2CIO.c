#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#define LED_PIN 25

// device register
#define ADDR _u(0b0100000) // should this be 0100000 or 01000000 

// hardware registers
#define REG_IODIR _u(0x00)
#define REG_GPIO _u(0x09)
#define REG_OLAT  _u(0x0A)


// which pins should be inputs, which pins should be outputs
void chip_init() {
    // use the "handheld device dynamic" optimal setting (see datasheet)
    uint8_t buf[2];

    // send register number followed by its corresponding value
    buf[0] = REG_IODIR;
    buf[1] = 0b01111111; // GP7 is an output, GP0 is an input, set everything else as an input
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false); // hopefully does start bit, all data, read ack, sends stop appropriately
}

void set(char v) {
    // use the "handheld device dynamic" optimal setting (see datasheet)
    uint8_t buf[2];

    // send register number followed by its corresponding value
    buf[0] = REG_OLAT;
    buf[1] = v<<7; // GP7 is an output, GP0 is an input, set everything else as an input
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false); // hopefully does start bit, all data, read ack, sends stop appropriately
}


uint8_t read_chip() {
    uint8_t buf;
    uint8_t reg = REG_GPIO;
    i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);  // true to keep master control of bus
    i2c_read_blocking(i2c_default, ADDR, &buf, 1, false);  // false - finished with bus

    //return buf;
    printf("GPIO register value: 0x%02x\n", buf);
    if((buf & 0x01) == 0x01){
        return 1; 
    }
    else {
        return 0;
    }
}


void rpi_heartbeat() {
    gpio_put(LED_PIN, 1);
    sleep_ms(45);
    gpio_put(LED_PIN, 0);
    sleep_ms(45);
    gpio_put(LED_PIN, 1);
    sleep_ms(45);
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
}

int main() {
    stdio_init_all();

    // from pico-examples for heartbeat
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    // configure chip
    chip_init();
    sleep_ms(250);

    while (1) {
        // blink-25
        //printf("Start heartbeat");
        //printf("\n");
        rpi_heartbeat();

        /*
        // Part 1: set LED high
        set(1);
        sleep_ms(100);
        set(0);
        */

       
        // Part 2: control with button
        uint8_t button = read_chip();
        //printf("Button: ");
        //printf("%d", button);
        //printf("\n");

        if(button==1) {
            set(1);
        }
        else {
            set(0);
        }
        

        //printf("End read_chip()");
        //printf("\n");
        sleep_ms(10);
    }
}

// The goal is to read from GP0, and if the button is pushed, turn on GP7, 
// else turn off GP7. Blink the builtin green LED that is connected directly 
// to the Pico at some frequency as a heart-beat, so that you know the 
// Pico is running.

// Part 1: chip initialization and blink the LED on GP7 
// Part 2: read from GP0 and control GP7

// The chip must be initialized so that GP7 is an output pin and GP0 is input. 
// You can make all the other pins inputs. Write an unsigned char to IODIR like 
// you would a TRIS register in the PIC.

// Set the bits in OLAT to turn the pins on or off, and read from GPIO to know 
// if the button is pushed or not. Note that there are no structures like LATAbits. 
// or PORTBbits. built into the code, so you'll probably need some bitshifting and 
// ANDing and ORing to identify individual bits from the unsigned chars.

// I suggest creating general purpose write and read functions, like 
// 'void setPin(unsigned char address, unsigned char register, unsigned char value)', 
// and 'unsigned char readPin(unsigned char address, unsigned char register)', 
// we'll use them or similar functions in future assignments.