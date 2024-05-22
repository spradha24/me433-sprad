add_executable(OLED
    OLED.c
    ssd1306.c
)

target_sources(OLED PRIVATE OLED.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(OLED pico_stdlib hardware_i2c hardware_adc)

# Enable standard I/O over USB
pico_enable_stdio_usb(OLED 1)

# Disable standard I/O over UART
pico_enable_stdio_uart(OLED 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(OLED)
