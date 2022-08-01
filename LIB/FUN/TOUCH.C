#include    "../../20160607_LIBV413/USER_PROGRAM/USER_PROGRAM.H"  
#include "TOUCH.H"
#include "GPIO.H"
#include "../STRUCT.H"
#include "../USER_SETING.H"

extern struct ST_jaroo  jaroo;
extern struct ST_touch  touch;

char touch_read(unsigned char num_touch , unsigned char temp_touch , unsigned char *temp_timer ){
	
	if( DATA_BUF[0]&(0x01<<num_touch)  ){
			
		if( num_touch == t_less )tled_less=0;
		if( num_touch == t_pluse )tled_pluse=0;
				
		if( temp_timer[temp_touch] == 0 ){
				
			temp_timer[temp_touch]=200;
			return 1;
			
		}	
	
	}
	else { temp_timer[temp_touch]=0; 
	
		if( num_touch == t_less )tled_less=1;
		if( num_touch == t_pluse )tled_pluse=1;
	
	}
	
	if( temp_timer[temp_touch] > 0 ) temp_timer[temp_touch]--;	
	
	return 0;
	
}

void touch_led_manage(){
	
	if( touch_read(t_less , temp_less , (unsigned char *)&touch.TEMP  ) )if( jaroo.LEVEL > 0) jaroo.LEVEL--;	
	if( touch_read(t_pluse , temp_pluse , (unsigned char *)&touch.TEMP  ) )if( jaroo.LEVEL < 4) jaroo.LEVEL++;			
			
	led1=0; led2=0; led3=0; led4=0; led5=0; 
	if( jaroo.LEVEL == 0 ){ led1=1; jaroo.POWER=POWER_LEVEL1; }
	if( jaroo.LEVEL == 1 ){ led2=1; jaroo.POWER=POWER_LEVEL2; }
	if( jaroo.LEVEL == 2 ){ led3=1; jaroo.POWER=POWER_LEVEL3; }
	if( jaroo.LEVEL == 3 ){ led4=1; jaroo.POWER=POWER_LEVEL4; }
	if( jaroo.LEVEL == 4 ){ led5=1; jaroo.POWER=POWER_LEVEL5; }	
	
		
	
}