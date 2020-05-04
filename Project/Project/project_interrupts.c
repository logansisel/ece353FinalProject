#include "project_interrupts.h"

static volatile uint16_t PS2_X_DATA = 0;
static volatile uint16_t PS2_Y_DATA = 0;
static volatile PS2_DIR_t PS2_DIR = PS2_DIR_CENTER;
PS2_DIR_t direction = PS2_DIR_CENTER; // Keep track of spaceship direction
volatile bool ALERT_DRAW = false;
volatile bool ALERT_STAY = false;
volatile bool ALERT_BUTTON = false;
volatile int8_t CYCLE = 0;
uint32_t i;
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
// TIMER1 ISR is used to breath LED
//*****************************************************************************
void TIMER1A_Handler(void)
{	
	static int number = 0;	
	if (number < CYCLE) lp_io_set_pin(BLUE_BIT);	
	else lp_io_clear_pin(BLUE_BIT);		
  number = (number+1) % 100;
	
  // Clear the interrupt
	TIMER1->ICR |= TIMER_ICR_TATOCINT;
}

//*****************************************************************************
// TIMER2A ISR is used to breath LED
//*****************************************************************************
void TIMER2A_Handler(void)
{	
		

	static bool myBool;	
	
	if (CYCLE == -45) myBool = true;
	else if(CYCLE == 100) myBool = false;
	
	
	if (myBool) CYCLE = CYCLE + 1;
	else CYCLE = CYCLE - 1;
	
		
	
  // Clear the interrupt
	TIMER2->ICR |= TIMER_ICR_TATOCINT;
	
}

//*****************************************************************************
// TIMER3 ISR is for joystick inputs 
//*****************************************************************************
void TIMER3A_Handler(void)
{		
	// if pulled down, draw a card
	if (PS2_DIR == PS2_DIR_DOWN){
		ALERT_DRAW = true;
	}
	// if pulled down, draw a card
	if (PS2_DIR == PS2_DIR_UP){
		ALERT_STAY = true;
	}

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

// GPIOF is used to detect button presses
void GPIOF_Handler(void)
{
	//printf("ddddddddddd");
	ALERT_BUTTON = true;
	GPIOF->ICR |= GPIO_ICR_GPIO_M;
}






