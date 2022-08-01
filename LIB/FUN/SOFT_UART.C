#include    "../../20160607_LIBV413/USER_PROGRAM/USER_PROGRAM.H"  
#include    "SOFT_UART.H"  
#include "../STRUCT.H"

extern struct ST_soft_usart_RX soft_usart_RX;



void soft_uart_ini(){
	
	//PORT_RX=1;
	PORT_TX=0;
	
	TX=1;
	
	
}



#define delay_soft_uart_9600 4

/*
void soft_uart_send_byte( unsigned char data){
		
	while(1){
		TX=1;
		uart_delay(delay_soft_uart_9600);	
		TX=0;
		uart_delay(delay_soft_uart_9600);	
	}
	
		int cont;
		TX=0;	uart_delay(delay_soft_uart_9600);
		for(cont=1; cont<256; cont*=2 ){
			 if(data & cont)TX=1;
			 else TX=0;
			uart_delay(delay_soft_uart_9600);	
		}		
		TX=1; uart_delay(delay_soft_uart_9600*2);	
}*/
//------------------------------------rx

/*

unsigned char soft_uart_get_byte(){

	unsigned char data=0;
	int cont=0;
	
	uart_delay(delay_soft_uart_9600+delay_soft_uart_9600/2);
	for(cont=1; cont<256; cont*=2 ){
			data |= (cont * RX );
			uart_delay(delay_soft_uart_9600);	
	}	
	uart_delay(delay_soft_uart_9600/2);
	return data;
}
*/