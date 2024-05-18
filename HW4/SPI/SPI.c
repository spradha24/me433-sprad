#include <stdio.h>
#include <math.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"

// Need these 
static inline void cs_select() {
    asm volatile("nop \n nop \n nop");
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 0);  // Active low
    asm volatile("nop \n nop \n nop");
}
static inline void cs_deselect() {
    asm volatile("nop \n nop \n nop");
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);
    asm volatile("nop \n nop \n nop");
}

#define DC_OFFSET 1.65
#define AMPLITUDE 1.65
//#define STEPS 100
#define SINE_FREQUENCY 2
#define TRI_FREQUENCY 1

/* // sineWave array function courtesy of MicroChip website but it didn't really work so this is actually unused, just keeping for history
void sine_wave_table(uint16_t *table, int sine_wave_steps){
    for(int i = 0; i < SINE_WAVE_STEPS; i++) {
        table[i] = SINE_DC_OFFSET + SINE_AMPLITUDE * sin(i * 2 * 3.1415 / SINE_WAVE_STEPS);
    }
}
*/

// write_register function
static void write_register(uint8_t channel, uint16_t volt_bin) { // 1st bit channel A or B, 16st bits only 10 for the voltage, 
    uint8_t buf[2]; // unsigned integer of length 8 bits
    //buf[0] = channel & 0x7f;  // first 8 bit numbers, if channel is 0 (A) --> 0000 0000, if channel is 1 (B) --> 0000 0001
    //buf[1] = volt_bin; // second 16 bit numbers, 0000 0011 1111 1111 would be 3.3V

    buf[0] = (channel << 7) | (0x07 << 4) | ((volt_bin >> 6) & 0x0F); // left shift channel by 7 | left shift 0000 0111 by 4 | right shift volt_bin by 6 and mask with 0000 1111
    buf[1] = (volt_bin << 2) & 0xFC; // left shift volt_bin by 2 and mask with 1111 1100

    cs_select();
    spi_write_blocking(spi_default, buf, 2);
    cs_deselect();
}

/* //Troubleshooting to see if write_register worked as expected
//Helper function to print the binary representation of a number
static void print_binary(uint32_t num, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

static uint16_t write_register(uint8_t channel, uint16_t volt_bin) {
    uint8_t buf_0 = (channel << 7) | (0x07 << 4) | ((volt_bin >> 6) & 0x0F); // left shift channel by 7 | left shift 0000 0111 by 4 | right shift volt_bin by 6 and mask with 0000 1111
    uint8_t buf_1 = (volt_bin << 2) & 0xFC; // left shift volt_bin by 2 and mask with 1111 1100
    uint16_t result = ((uint16_t)buf_0 << 8) | buf_1; // left shift buf_0 by 8 | buf_1

    printf("Buf[0] (binary): ");
    print_binary(buf_0, 8);
    printf("\n");
    printf("Buf[1] (binary): ");
    print_binary(buf_1, 8);
    printf("\n");
    printf("Result (binary): ");
    print_binary(result, 16);
    printf("\n");

    return result;
}
*/

// converting the regular voltage input to uint16_t
uint16_t convert_volt_out(float voltage) {
    if (voltage < 0.0) {
        voltage = 0.0;
    } else if (voltage > 3.3) {
        voltage = 3.3;
    }
    return (uint16_t)(round(voltage*1023)/3.3);
}


int main() {
    stdio_init_all(); // always, turns on pins, speeds, memory
    
    spi_init(spi_default, 10*1000000); //initialization and baud rate, using SPI0 
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI); // SCK pin on Pico is GPIO18
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI); // TX pin on Pico is GPIO19

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(PICO_DEFAULT_SPI_CSN_PIN);
    gpio_set_dir(PICO_DEFAULT_SPI_CSN_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);

    //uint16_t volt_bin = 0x38C; // 0000 0011 1000 1100
    //uint16_t volt_bin = 908;
    //uint16_t volt_bin = 0x0184; // 184_6 = 388_10 = 0000 0001 1000 0100_2
    //float volt_outA = 2.5;
    //uint16_t volt_binA = convert_volt_out(volt_outA);
    //uint16_t sineTable[SINE_WAVE_STEPS];
    //sine_wave_table(sineTable, SINE_WAVE_STEPS);
    //int i = 0;

    uint8_t channelA = 0; // channel A
    uint8_t channelB = 1; // channel B

    float time_A = 0.0; // optimization is not my best friend
    float time_B = 0.0; // forgive me
    float dt = 0.005;

    while (1) {
        // channel A stuff
        //float volt_outA = 2.5;
        float volt_outA = DC_OFFSET + AMPLITUDE * sin(2 * 3.1415 * SINE_FREQUENCY * time_A);
        uint16_t volt_binA = convert_volt_out(volt_outA);
        write_register(channelA, volt_binA);

        time_A += dt;
        if (time_A >= (1.0 / SINE_FREQUENCY)) {
            time_A = 0.0; 
        }

        // channel B stuff
        //float volt_outB = 1;
        float volt_outB; 
        if (time_B < 0.25) {
            volt_outB = DC_OFFSET + 6.6 * time_B;
        }
        if (time_B >= 0.25 && time_B <= 0.75) {
            volt_outB = 3 * DC_OFFSET - 6.6 * time_B;
        }
        if (time_B >= 0.75 && time_B < 1) {
            volt_outB = -3 * DC_OFFSET + 6.6 * time_B;
        }
        uint16_t volt_binB = convert_volt_out(volt_outB);
        write_register(channelB, volt_binB);

        time_B += dt;
        if (time_B > (1.0 / TRI_FREQUENCY)) {
            time_B = 0.0; 
        }
/*        printf("time = ");
        printf("%3f",time_B);
        printf("\n");
        printf("Volt_outB = ");
        printf("%2.2f",volt_outB);
        printf("\n");*/

        sleep_ms(10);
    }

    return 0;
}