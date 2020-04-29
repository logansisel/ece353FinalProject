// Copyright (c) 2015-19, Joe Krachey
// All rights reserved.
//
// Redistribution and use in source or binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in source form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "main.h"


//*****************************************************************************
//*****************************************************************************
void DisableInterrupts(void)
{
  __asm {
         CPSID  I
  }
}

//*****************************************************************************
//*****************************************************************************
void EnableInterrupts(void)
{
  __asm {
    CPSIE  I
  }
}


//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// Initializes all of the peripherls used in Project
//*****************************************************************************
void init_hardware(void)
{
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);
  ps2_initialize();
  
	// timer 1 is for blinking LED, timer 4 is for checking ADC
  gp_timer_config_32(TIMER1_BASE,TIMER_TAMR_TAMR_PERIOD, 1000000, false, true);
  gp_timer_config_32(TIMER4_BASE,TIMER_TAMR_TAMR_PERIOD, 50000, false, true);
}


int 
main(void)
{
	
uint8_t chipCount;
uint8_t playerScore;
uint8_t botScore;
uint8_t playerCards;
uint8_t botCards;
uint16_t genVal;	
uint16_t cardVal;
bool game_over;
	
initialize_serial_debug();
init_hardware();

while (1) {
	
	// set chip count at 4, start game
	chipCount = 4;
	game_over = false;
	
	// display main menu
	
	// wait for screen touch
	while(1);

	// game loop
	while (!game_over) {
		playerScore = 0;
		botScore = 0;
		playerCards = 0;
		botCards = 0;
		
		// give bot random card
		genVal = generate_random_number() % 13;
		// update bot score
		if (genVal == 1)
			cardVal = 11;
		else if (genVal == 11 || genVal == 12 || genVal == 0)
			cardVal = 10;
		else
			cardVal = genVal;
		botScore = botScore + cardVal;
		botCards++;
		// put card to screen
		// TODO
		
		// give player first random card
		genVal = generate_random_number() % 13;		
		// update user score
		if (genVal == 1)
			cardVal = 11;
		else if (genVal == 11 || genVal == 12 || genVal == 0)
			cardVal = 10;
		else
			cardVal = genVal;
		playerScore = playerScore + cardVal;
		playerCards++;
		// put card to screen
		// TODO
		
		// give player second random card
		genVal = generate_random_number() % 13;
		// update user score
		if (genVal == 1) 
			cardVal = 11;
		else if (genVal == 11 || genVal == 12 || genVal == 0)
			cardVal = 10;
		else
			cardVal = genVal;
		playerScore = playerScore + cardVal;
		playerCards++;
		// put card to screen
		// TODO
		
		// wait for user input
		while (1) {	
			// user inputs draw card
			if (1) {
				// give player random card
				genVal = generate_random_number() % 13;		
				// update user score
				if (genVal == 1)
					cardVal = 11;
				else if (genVal == 11 || genVal == 12 || genVal == 0)
					cardVal = 10;
				else
					cardVal = genVal;
				playerScore = playerScore + cardVal;
				playerCards++;
				// put card to screen
				// TODO
			}
			// user inputs stay with current cards
			if (1) {
				break;
			}
			// user can have max 4 cards, auto stay if at 4
			if (playerCards >= 4) {
				break;
			}
		}
		
		// make dealer bot pick cards
		while (1) {
			// bot draws until score is at least 17, maximum 4 total cards
			if (botScore < 17 && botCards < 4) {
				// give bot random card
				genVal = generate_random_number() % 13;
				// update bot score
				if (genVal == 1)
					cardVal = 11;
				else if (genVal == 11 || genVal == 12 || genVal == 0)
					cardVal = 10;
				else
					cardVal = genVal;
				botScore = botScore + cardVal;
				botCards++;
				// put card to screen
				// TODO
			}
			else
				break;
		}
		
		// turn over, determine winner	
		// player wins round
		if (playerScore > botScore && playerScore < 22) {
			chipCount++;
			// update LEDs
			// TODO
			// display win message
			// TODO
		}
		// bot wins round
		else {
			if (playerScore < botScore) {
				chipCount--;
				// update LEDs
				// TODO
				// display loss message
				// TODO
			}
			// tie
			if (playerScore == botScore) {
				// display tie message
				// TODO
			}
		}
		
		// check if game is over
		// player lost game
		if (chipCount == 0) {
			// display loss message
			game_over = true;
			
		}
		// player won game
		if (chipCount == 8) {
			// display win message
			game_over = true;
			
		}
		// clear screen
	}
}

// won't reach
while(1){};
}

