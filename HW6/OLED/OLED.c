#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "font.h"
#include "ssd1306.h"

//void drawPixel(int x, int y, int color);

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

void drawMessage(int x, int y, char * m) {
    int i = 0;
    while(m[i] != '\0') {
        drawChar(x, y, m[i]);
        x += 5;
        i++;
    }
}

int main() {
    stdio_init_all();
 
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    adc_init(); // initialize the adc module
    adc_gpio_init(26); // use pin 26 as an analog input
    adc_select_input(0); // read from ADC0

    ssd1306_setup();

    //char test1[25] = "abcdefghijklmnopqrstuvwxy";
    //char test2[25] = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    //char test3[25] = "YXWVUTSRQPONMLKJIHGFEDCBA";
    //char test4[25] = "yxwvutsrqponmlkjihgfedcba";
    char message[25];
    //int i = 8;

    while(1) {
        //ssd1306_drawPixel(10, 10, 1);
        //drawChar(10, 10, 'S');
        //drawChar(15, 10, 'I');
        //drawChar(20, 10, 'D');
        //drawChar(25, 10, 'D');
        //ssd1306_update();
        //sleep_ms(1000);
        //ssd1306_drawPixel(10, 10, 0);
        //ssd1306_update();
        //sleep_ms(1000);
        uint16_t result = adc_read();
        float voltage = result*3.3/4096;

        //printf("voltage: %.2f V\n", voltage); // print voltage to screen

        unsigned int start = to_us_since_boot(get_absolute_time());
        sprintf(message, "Voltage = %.2f V", voltage);
        //drawMessage(0, 0, test1);
        //drawMessage(0, 7, test2);
        //drawMessage(0, 14, test3);
        //drawMessage(0, 21, test4);
        drawMessage(6, 9, message);
        ssd1306_update();
        //i++;
        unsigned int stop = to_us_since_boot(get_absolute_time());

        float t = stop - start;
        float fps = 1000000.0 / t;

        //printf("Start: %.2f s\n", start); // print voltage to screen
        //printf("Stop: %.2f s\n", stop); // print voltage to screen
        //printf("Time: %.2f s\n", t); // print voltage to screen
        //printf("FPS = %.2f \n", fps);

        sprintf(message, "FPS = %.2f", fps);
        drawMessage(6, 18, message);
        ssd1306_update();
        sleep_ms(100) ;

        //sleep_ms(500);
    }
} 