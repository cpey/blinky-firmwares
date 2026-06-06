#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "main.h"

/* Simple UART printf */
void printf_uart(const char* str)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 100);
}

/* Print byte array in hex */
void print_hex(const uint8_t* data, int len)
{
    char buf[4];
    for (int i = 0; i < len; i++) {
        sprintf(buf, "%02X ", data[i]);
        HAL_UART_Transmit(&huart2, (uint8_t*)buf, 3, 50);
        if ((i + 1) % 16 == 0) {
            printf_uart("\r\n          ");
        }
    }
    printf_uart("\r\n");
}
