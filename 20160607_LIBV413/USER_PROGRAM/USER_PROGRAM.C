
#include "USER_PROGRAM.H"  
#include "../../LIB/BS83B08A/TIMER.H"        
#include "../../LIB/FUN/SOFT_UART.H"
#include "../../LIB/STRUCT.H"

struct ST_soft_usart_RX soft_usart_RX;
struct ST_soft_usart_RX soft_usart_TX;


#define vector_multy_fun0_interupt 0x0C

#define vector_ex_interupt 0x04


//----------------------------------

#define gate1 _pa1
#define port_gate1 _pac1

#define gate2 _pa3
#define port_gate2 _pac3

#define gate3 _pa0
#define port_gate3 _pac0

#define gate4 _pa7
#define port_gate4 _pac7

//----------------------------------

#define led_t1 _pb1
#define port_led_t1 _pbc1

#define led_t2 _pb2
#define port_led_t2 _pbc2

#define led_t3 _pb6
#define port_led_t3 _pbc6

#define led_t4 _pb5
#define port_led_t4 _pbc5

#define t1 0
#define t2 3
#define t3 4
#define t4 7

#define delay_rx 17
void delay_cpu( volatile int cpu_comp ){
	
	volatile int cpu=0;
	while(cpu<cpu_comp)cpu++;
	
}

volatile int timer_delay;
volatile unsigned char level=0;
volatile unsigned char rx_start=0;
volatile unsigned char tx_start=0;

volatile unsigned char level_rx=0;

unsigned char i=0;
unsigned char temp_touch[8];

volatile unsigned char touch;


void __attribute((interrupt(vector_multy_fun0_interupt)))  timer()
{ 
	//_tmr = 50;
	//timer_delay++;
		_ton=0;
		
	if( tx_start  ){
		
		if( level == 0 )TX=0;
		else if( soft_usart_TX.DATA & (0x01<<(level-1)) )TX=1;
		else TX=0;
		level++;
		if( level == 10 ){ TX=1; level=0; tx_start=0;
		
			_ints0=1; _ints1=1;
		
		}
		else { 
			_tmr = 137;
			_ton=1;
		}
		
				
	} 
	
	if( rx_start  ){
		
		if( _pa4  )soft_usart_RX.DATA =  soft_usart_RX.DATA | ( 0x01<<level_rx )  ;	
		
		
		level_rx++;
		if( level_rx == 8 ){ level_rx=0; rx_start=0;
		
				tx_start=1;
				soft_usart_TX.DATA =  soft_usart_RX.DATA;
				touch = soft_usart_RX.DATA ;
				
				_tmr = 137;
				_ton=1;				
			
			//soft_usart_TX.DATA = soft_usart_RX.DATA - 1 ;
			

		}
		else{	
			_tmr = 137;
			_ton=1;				
		}
		
			
	}
	
	

}

void __attribute((interrupt(vector_ex_interupt)))  ex_interupt()
{ 

	
	_ints0=0; _ints1=0;
	
	
	_pac4=1;
	_papu4=1;

	 rx_start=1; level_rx=0;
	 soft_usart_RX.DATA=0x00;

	_tmr = 100;
	_ton=1;	
		
}


void ex_init(){

_ints0=1; _ints1=1;
/*INTS1, INTS0: Defines INT interrupt active edge
00: Disabled interrupt
01: Rising Edge interrupt
10: Falling Edge interrupt
11: Dual Edge interrupt*/
_inte=1;
	
}



void ini_main(){
	
	 clock_ini();
	 
	port_led_t1=0;
	port_led_t2=0;
	port_led_t3=0;
	port_led_t4=0;	
	
	port_gate1=0;
	port_gate2=0;
	port_gate3=0;
	port_gate4=0;
	
}



void USER_PROGRAM_INITIAL()
{

	ini_main();
	
	timer_ini();
	timer_interupt_enable();
	ex_init();
	
	soft_uart_ini();
	
	
}





void touch_change(unsigned char loc){
	
	unsigned char temp = 0x01<<loc;
    if( touch & temp )touch &= ~ temp;
    else touch |= temp;	
	
}

void touch_pro( unsigned char num_touch  ){
	
	if( temp_touch[num_touch] == 0 ){		
		if( DATA_BUF[0]&(0x01<<num_touch)  ){
		
			if( num_touch == t1 ) touch_change(0);
			if( num_touch == t2 ) touch_change(1);
			if( num_touch == t3 ) touch_change(2);
			if( num_touch == t4 ) touch_change(3);
			
			temp_touch[num_touch]=200;
			
			while(tx_start == 1 ){}
			_ton=1; tx_start=1; soft_usart_TX.DATA=touch;
			
		}
	}
	else temp_touch[num_touch]--;
		
}

void USER_PROGRAM()
{
										
	
	GET_KEY_BITMAP();
	

	touch_pro(t1);
	touch_pro(t2);
	touch_pro(t3);
	touch_pro(t4);  		
	
	
	
	if( touch&(0x01<<0) ) led_t1=0;
	else led_t1=1;
	
	if( touch&(0x01<<1) ) led_t2=0;
	else led_t2=1;
	
	if( touch&(0x01<<2) ) led_t3=0;
	else led_t3=1;
	
	if( touch&(0x01<<3) ) led_t4=0;
	else led_t4=1;	


	
	if( touch&(0x01<<4) ) gate1=1;
	else gate1=0;

	
	if( touch&(0x01<<5) ) gate2=1;
	else gate2=0;
	
		
	if( touch&(0x01<<6) ) gate3=1;
	else gate3=0;
	
		
	if( touch&(0x01<<7) ) gate4=1;
	else gate4=0;					
}






