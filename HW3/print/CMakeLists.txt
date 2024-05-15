add_executable(print)

target_sources(print PRIVATE print.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(print pico_stdlib hardware_adc)
pico_enable_stdio_usb(print 1)
pico_enable_stdio_uart(print 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(print)