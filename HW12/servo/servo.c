#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hardware/pwm.h"

//#define LEDPin 25 // the built in LED on the Pico
#define SERVOPin 2 // GPIO2

void servoAngle(float angle) {
    uint slice_num = pwm_gpio_to_slice_num(SERVOPin); // Get PWM slice number
    uint16_t wrap = 10000; // when to rollover, must be less than 65535

    float min_pulse = 0.5;
    float max_pulse = 2.5;
    float pulse = min_pulse + (angle/180.0)*(max_pulse - min_pulse);
    float wrap_mod = (pulse/20.0) * wrap;

    pwm_set_gpio_level(SERVOPin, wrap_mod);
}


int main() {
    stdio_init_all();
    //gpio_set_function(LEDPin, GPIO_FUNC_PWM); // Set the LED Pin to be PWM
    gpio_set_function(SERVOPin, GPIO_FUNC_PWM); // Set the SERVO Pin to be PWM
    
    uint slice_num = pwm_gpio_to_slice_num(SERVOPin); // Get PWM slice number
    float div = 250; // must be between 1-255
    pwm_set_clkdiv(slice_num, div); // divider
    uint16_t wrap = 10000; // when to rollover, must be less than 65535
    pwm_set_wrap(slice_num, wrap);
    pwm_set_enabled(slice_num, true); // turn on the PWM

    //pwm_set_gpio_level(SERVOPin, wrap / 2); // set the duty cycle to 50%

    while (1) {
        //unsigned int start = to_us_since_boot(get_absolute_time());
        for (int a = 0; a <= 180; a++){
            servoAngle(a);
            sleep_ms(2000/180); // 2 seconds to get there
        }
        for (int a = 180; a >= 0; a--){
            servoAngle(a);
            sleep_ms(2000/180); // 2 seconds to get there
        }
        //unsigned int stop = to_us_since_boot(get_absolute_time());
        //float t = stop - start;
        //printf("Time: %d", t);
    }
}