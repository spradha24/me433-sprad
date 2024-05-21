add_executable(I2CIO)

target_sources(I2CIO PRIVATE I2CIO.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(I2CIO pico_stdlib hardware_i2c)

# Enable standard I/O over USB
pico_enable_stdio_usb(I2CIO 1)

# Disable standard I/O over UART
pico_enable_stdio_uart(I2CIO 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(I2CIO)
