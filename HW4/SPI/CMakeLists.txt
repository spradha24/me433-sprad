add_executable(SPI)

target_sources(SPI PRIVATE SPI.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(SPI pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(SPI)
