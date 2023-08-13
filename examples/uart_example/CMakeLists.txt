add_executable(uart_example
    uart_example.c
    uart_transport.c
)
target_link_libraries(uart_example
    pico_stdlib
    # hardware_uart
    microros
)

target_include_directories(uart_example PUBLIC
    ../../libmicroros/include
    ../../
)

SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections")

# Configure Pico
pico_enable_stdio_usb(uart_example 0)
pico_enable_stdio_uart(uart_example 1)
add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)

# Generate UF2
pico_add_extra_outputs(uart_example)
