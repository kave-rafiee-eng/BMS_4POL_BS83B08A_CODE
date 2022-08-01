#ifndef _SOFT_UART_H
#define _SOFT_UART_H

#define RX _pa0
#define PORT_RX _pac0

#define TX _pa2
#define PORT_TX _pac2


unsigned char soft_uart_get_byte();
void soft_uart_send_byte( unsigned char data);
unsigned char soft_uart_rx_check();

#endif


