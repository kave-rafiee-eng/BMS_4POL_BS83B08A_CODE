#include    "../../20160607_LIBV413/USER_PROGRAM/USER_PROGRAM.H"  
#include "TIMER.H"

void timer_ini(){
	
	_ts=0;	
/*TS: Timer/Event Counter Clock Source
0: fSYS
1: fSUB	*/

	_tpsc0=1;_tpsc1=1;_tpsc2=1;	
/*	TPSC2~TPSC0: Timer prescaler rate selection
Timer internal clock=
000: fTP
001: fTP/2
010: fTP/4
011: fTP/8
100: fTP/16
101: fTP/32
110: fTP/64
111: fTP/128*/

	_ton=1;
/*
TON: Timer/Event Counter Counting Enable
0: Disable
1: Enable*/
	
		
}

void timer_interupt_enable(){

	_emi=1;
	_te=1;	
	
}
