#include "ws2812b.h"


void ws2812b_rotate(WS2812B_t *base, uint8_t num_leds){
	WS2812B_t temp = base[num_leds-1];
	for (int i = num_leds-1; i > 0; i--){
    base[i] = base[i-1];
	}		
	base[0] = temp;
}


void ws2812b_pulse(WS2812B_t *base, uint8_t num_leds){
	static int direction = 0; // 1 if incrementing
	uint8_t i, j;
	for (j = 0; j < num_leds; j++){
	  if (direction && base[j].red < 0xFF){
		  for (i = 0; i < num_leds; i++)
		    base[j].red++;
  	}	
  	else if (direction && base[j].red == 0xFF){
	    direction = 0;
		  for (i = 0; i < num_leds; i++)
		    base[j].red--;
	
	  }
	  else if (!direction && base[j].red > 0x00){
		  for (i = 0; i < num_leds; i++)
		    base[j].red--;
	
	  }
	  else if (!direction && base[j].red == 0x00){
	    direction = 1;
		  for (i = 0; i < num_leds; i++)
		    base[j].red++;
	
	  }
	}
}
