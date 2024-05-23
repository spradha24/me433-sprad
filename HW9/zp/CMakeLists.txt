add_executable(zp)

target_sources(zp PRIVATE zp.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(zp pico_stdlib hardware_uart hardware_irq hardware_i2c)

# Enable standard I/O over USB
pico_enable_stdio_usb(zp 1)

# Disable standard I/O over UART
pico_enable_stdio_uart(zp 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(zp)
