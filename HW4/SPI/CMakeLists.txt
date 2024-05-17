add_executable(SPI)

target_sources(SPI PRIVATE SPI.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(SPI pico_stdlib hardware_spi)

# Enable standard I/O over USB
pico_enable_stdio_usb(SPI 1)

# Disable standard I/O over UART
pico_enable_stdio_uart(SPI 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(SPI)
