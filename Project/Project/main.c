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

const int dealerColor = LCD_COLOR_RED;
const int playerColor = LCD_COLOR_YELLOW;
const int cardWidth = 73;
const int cardHeight = 91;

const int playerCard1x = 200;
const int playerCard1y = 270;
const int playerCard2x = 125;
const int playerCard2y = 270;
const int playerCard3x = 50;
const int playerCard3y = 270;
const int playerCard4x = 200;
const int playerCard4y = 177;

const int dealerCard1x = 38;
const int dealerCard1y = 45;
const int dealerCard2x = 113;
const int dealerCard2y = 45;
const int dealerCard3x = 188;
const int dealerCard3y = 45;
const int dealerCard4x = 38;
const int dealerCard4y = 138;




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
	init_serial_debug(true,true);
	
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);
  ps2_initialize();
  
  // We need these 3 values or else it doesn't work, not sure why
  gp_timer_config_32(TIMER2_BASE,TIMER_TAMR_TAMR_PERIOD, 1000000, false, true);
  gp_timer_config_32(TIMER3_BASE,TIMER_TAMR_TAMR_PERIOD, 500000, false, true);
  gp_timer_config_32(TIMER4_BASE,TIMER_TAMR_TAMR_PERIOD, 50000, false, true);
}

void _2D( int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
		  lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_2DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
	
}

void _3D( int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
		lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_3DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
}

void _4D(int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
			lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_4DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color          // Background Color
                        );
}

void _5D(int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
		lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth + 2,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_5DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color          // Background Color
                        );
}
void _6D(int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
				lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_6DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}
void _7D(int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
					lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_7DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color          // Background Color
                        );
	
}
void _8D(int x, int y){
	
	         int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
						lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_8DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color        // Background Color
                        );
	
}
void _9D(int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
	lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_9DBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}
void _TD(int x, int y){
	
		int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
	lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_TDBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}
void _JD(int x, int y){
	
		int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
	lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_JDBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}
void _QD(int x, int y){
	
		int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
	lcd_draw_image(
                          x,                       // X Center Point
                          72,   // Image Horizontal Width
                          y,                       // Y Center Point
                          89,  // Image Vertical Height
                          Image_QDBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}
void _KD(int x, int y){
	
		int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
	lcd_draw_image(
                          x,                       // X Center Point
                          71,   // Image Horizontal Width
                          y,                       // Y Center Point
                          89,  // Image Vertical Height
                          Image_KDBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}
void _AD(int x, int y){
	
		int color = 0;
	if(y > 150){
		color = playerColor;
	}else {
		color = dealerColor;
	}
	
	lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_ADBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          color         // Background Color
                        );
	
}

int getCard(int card, int number, int dealer){
	
	int x = 0;
	int y = 0;
	
	if(number == 0){
		if(dealer == 1){
			x = dealerCard1x;
			y = dealerCard1y;
		}else{
			x = playerCard1x;
			y = playerCard1y;
		}
	}else if (number == 1){
		if(dealer == 1){
			x = dealerCard2x;
			y = dealerCard2y;
		}else{
			x = playerCard2x;
			y = playerCard2y;
		}
		
	}else if (number == 2){
		if(dealer == 1){
			x = dealerCard3x;
			y = dealerCard3y;
		}else{
			x = playerCard3x;
			y = playerCard3y;
		}
	}else if (number == 3){
		if(dealer == 1){
			x = dealerCard4x;
			y = dealerCard4y;
		}else{
			x = playerCard4x;
			y = playerCard4y;
		}
	}
	
	if(card == 0){
		_KD(x,y);
	}else if (card == 1){
		_AD(x,y);
	}else if (card == 2){
		_2D(x,y);
	}else if (card == 3){
		_3D(x,y);
	}else if (card == 4){
		_4D(x,y);
	}else if (card == 5){
		_5D(x,y);
	}else if (card == 6){
		_6D(x,y);
	}else if (card == 7){
		_7D(x,y);
	}else if (card == 8){
		_8D(x,y);
	}else if (card == 9){
		_9D(x,y);
	}else if (card == 10){
		_TD(x,y);
	}else if (card == 11){
		_JD(x,y);
	}else if (card == 12){
		_QD(x,y);
	}
	
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
	

init_hardware();

	
while (1) {
	
	srand(46); // random seed
	// set chip count at 4, start game
	chipCount = 4;
	game_over = false;
	
	// display main menu
	
	// wait for screen touch
	
	//while(1);
  	while (!game_over) {
		playerScore = 0;
		botScore = 0;
		playerCards = 0;
		botCards = 0;
		
		// give bot random card
		genVal = rand() % 13;
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
		getCard(genVal,0,true); // Place first dealer card
		// TODO
		
		// give player first random card
		genVal = rand() % 13;		
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
		getCard(genVal,0,false); // Place first player card
		// TODO
		
		// give player second random card
		genVal = rand() % 13;
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
		getCard(genVal,1,false); // Place second dealer card
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
		game_over = true; // Test to make it stop runnning forever
	}
}
	// game loop


// won't reach
while(1){};
}



