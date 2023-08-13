add_executable(usb_example
    usb_example.c
    usb_transport.c
)
target_link_libraries(usb_example
    pico_stdlib
    microros
)

target_include_directories(usb_example PUBLIC
    ../../libmicroros/include
    ../../
)

SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections")

# Configure Pico
pico_enable_stdio_usb(usb_example 1)
pico_enable_stdio_uart(usb_example 0)
add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)

# Generate UF2
pico_add_extra_outputs(usb_example)
