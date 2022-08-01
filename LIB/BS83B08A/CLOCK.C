#include    "../../20160607_LIBV413/USER_PROGRAM/USER_PROGRAM.H"  
#include "CLOCK.H"
void clock_ini(){
	
	_smod = 0x00;
	
	_hlclk = 1;
/*
HLCLK: System Clock Selection
0: fH/2~fH/64 or fSUB
1: fH*/

	_hircs1=0; _hircs0=1;
/* HIRCS1~HIRCS0: High frequency clock select
00: 8MHz
01: 16MHz
10: 12MHz
11: 8MHz*/

_ws0=1; _ws1=1; _ws2=1;
/*WS2~WS0: WDT Time-out period selection
000: 28
/fSUB
001: 210/fSUB
010: 212/fSUB
011: 214/fSUB
100: 215/fSUB
101: 216/fSUB
110: 217/fSUB
111: 218/fSUB
These three bit*/
	
}