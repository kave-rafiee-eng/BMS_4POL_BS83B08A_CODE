#include    "../../20160607_LIBV413/USER_PROGRAM/USER_PROGRAM.H"  
#include "EX_INT.H"

void EX_INT_init(){

	_ints0=1; _ints1=1;
/*INTS1, INTS0: Defines INT interrupt active edge
00: Disabled interrupt
01: Rising Edge interrupt
10: Falling Edge interrupt
11: Dual Edge interrupt*/

	_inte=1;
	
}