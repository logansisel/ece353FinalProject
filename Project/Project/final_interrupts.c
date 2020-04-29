#include "hw3_interrupts.h"

static volatile uint16_t PS2_X_DATA = 0;
static volatile uint16_t PS2_Y_DATA = 0;
static volatile PS2_DIR_t PS2_DIR = PS2_DIR_CENTER;
int count = 0; // Global variable to keep track of count
PS2_DIR_t direction = PS2_DIR_CENTER; // Keep track of spaceship direction


//*****************************************************************************
// Returns the most current direction that was pressed.
//*****************************************************************************
PS2_DIR_t ps2_get_direction(void)
{
  
	if(PS2_X_DATA > PS2_ADC_HIGH_THRESHOLD){		
		PS2_DIR = PS2_DIR_LEFT; // If the joystick is to the left
	}else if (PS2_X_DATA < PS2_ADC_LOW_THRESHOLD){
		PS2_DIR = PS2_DIR_RIGHT; // If the joystick is to the right
	}else if (PS2_Y_DATA > PS2_ADC_HIGH_THRESHOLD){
		PS2_DIR = PS2_DIR_UP; // If the joystick is up
	}else if (PS2_Y_DATA < PS2_ADC_LOW_THRESHOLD){
		PS2_DIR = PS2_DIR_DOWN; // If the joystick is down
	}else{
		PS2_DIR = PS2_DIR_CENTER; // If none, then it's in the middle
	}
	return PS2_DIR; // Returns the set direction
	
}

//*****************************************************************************
// TIMER2 ISR is used to determine when to move the Invader
//*****************************************************************************
void TIMER2A_Handler(void)
{	
	if(!contact_edge(PS2_DIR, INVADER_X_COORD, INVADER_Y_COORD, invaderHeightPixels, invaderWidthPixels)){ // Check if not touching
		move_image(PS2_DIR, &INVADER_X_COORD, &INVADER_Y_COORD, invaderHeightPixels, invaderWidthPixels); // Move imagine accordingly
		ALERT_INVADER = true;
	}
    
    // Clear the interrupt
	TIMER2->ICR |= TIMER_ICR_TATOCINT;
}

//*****************************************************************************
// TIMER3 ISR is used to determine when to move the spaceship
//*****************************************************************************
void TIMER3A_Handler(void)
{	
	
	while(contact_edge(direction, SHIP_X_COORD, SHIP_Y_COORD, space_shipHeightPixels, space_shipWidthPixels) || count == 0){ // Check if the count is zero or if contacting edge
		
		direction = get_new_direction(direction); // Random generate direction
		count = get_new_move_count(); // Random generate movement count
		
	}
	
	count = count - 1; // One less
	
	move_image(direction, &SHIP_X_COORD, &SHIP_Y_COORD, space_shipHeightPixels, space_shipWidthPixels); // Draw image at new position
	
  ALERT_SPACE_SHIP = true;
	// Clear the interrupt
	TIMER3->ICR |= TIMER_ICR_TATOCINT;  
}

//*****************************************************************************
// TIMER4 ISR is used to trigger the ADC
//*****************************************************************************
void TIMER4A_Handler(void)
{	
	
	ADC0->PSSI |= ADC_PSSI_SS2;
	// Clear the interrupt
	TIMER4->ICR |= TIMER_ICR_TATOCINT; 
	
	
	
	
}

//*****************************************************************************
// ADC0 SS2 ISR
//*****************************************************************************
void ADC0SS2_Handler(void)
{
 
	PS2_X_DATA = ADC0->SSFIFO2; // Update joystick data
	PS2_Y_DATA = ADC0->SSFIFO2;
	ps2_get_direction(); // Get direction of joystick

	
	 // Clear the interrupt
  ADC0->ISC |= ADC_ISC_IN2;
	
}
