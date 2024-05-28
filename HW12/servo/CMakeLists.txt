add_executable(servo)

target_sources(servo PRIVATE servo.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(servo pico_stdlib hardware_uart hardware_irq hardware_i2c hardware_pwm)

# Enable standard I/O over USB
pico_enable_stdio_usb(servo 1)

# Disable standard I/O over UART
pico_enable_stdio_uart(servo 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(servo)
