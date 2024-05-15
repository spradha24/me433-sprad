#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define BTN_PIN_NUM 13
#define LED_PIN_NUM 15
#define ADC_PIN_NUM 26

int main() {
    stdio_init_all(); // always start main with this
    while (!stdio_usb_connected()) { // wait for usb port to be opened, happens when you plug in
        sleep_ms(100);
    }
    // initialization
    gpio_init(LED_PIN_NUM); // initialize LED pin GP15
    gpio_set_dir(LED_PIN_NUM, GPIO_OUT); // set direction as output
    gpio_put(LED_PIN_NUM, 1); // initially set as on

    adc_init(); // initialize the adc module
    adc_gpio_init(ADC_PIN_NUM); // use pin 26 as an analog input
    adc_select_input(0); // read from ADC0

    gpio_init(BTN_PIN_NUM); // initialize button pin GP13
    gpio_set_dir(BTN_PIN_NUM, GPIO_IN); // set direction as input
    gpio_pull_up(BTN_PIN_NUM); 

// Screen pulled up, start appears, button pressed, LED turns on, user prompted and enters, LED turns off and readings run, loop
    while (1) {
        printf("Start!\n"); // print this start 

        while (gpio_get(BTN_PIN_NUM)) {
            sleep_ms(100); 
        }
        gpio_put(LED_PIN_NUM, 0); // set as off

        printf("Enter n between 1 to 100: "); // print to screen prompt
        int n = 0; // initialize counter variable
        scanf("%d", &n); // scanf for number n

        for (int i = 0; i < n; i++) { // loop thru n samples
            uint16_t result = adc_read(); // read adc0
            float voltage = result*3.3/4096; // calculate float for voltage
            printf("voltage %d: %.2f V\n", i+1, voltage); // print voltage to screen
            sleep_ms(10); 
        }

        gpio_put(LED_PIN_NUM, 1); // reset as on
    }


}
