add_executable(UART)

target_sources(UART PRIVATE UART.c ssd1306.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(UART pico_stdlib hardware_uart hardware_irq hardware_i2c)

# Enable standard I/O over USB
pico_enable_stdio_usb(UART 1)

# Disable standard I/O over UART
pico_enable_stdio_uart(UART 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(UART)
