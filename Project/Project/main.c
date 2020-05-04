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

const int dealerColor = LCD_COLOR_GRAY;
const int playerColor = LCD_COLOR_WHITE;
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
	DisableInterrupts();
	init_serial_debug(true,true);
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);
  ps2_initialize();
	ft6x06_init();
	eeprom_init();
	lp_io_init();
	io_expander_init();
	EnableInterrupts();

	
  gp_timer_config_32(TIMER1_BASE,TIMER_TAMR_TAMR_PERIOD, 5000, false, true); // breathingLED
	gp_timer_config_32(TIMER2_BASE, TIMER_TAMR_TAMR_PERIOD, 1000000, false, true); // breathing LED
  gp_timer_config_32(TIMER3_BASE,TIMER_TAMR_TAMR_PERIOD, 5000, false, true); // touch screen
  gp_timer_config_32(TIMER4_BASE,TIMER_TAMR_TAMR_PERIOD, 5000, false, true); // other timer
}

void waitTime(int time) {
	int i;
	time = time * 100; // function to wait 
	for (i = 0; i < time; i++) {}
}

//The following 13 functons are for drawing each of the 13 cards in their respecitve location
void _2D( int x, int y){
	
	int color = 0;
	if(y > 150){
		color = playerColor; // Determine if play or dealer card
	}else {
		color = dealerColor;
	}
		  lcd_draw_image(
                          x,                       // X Center Point
                          cardWidth,   // Image Horizontal Width
                          y,                       // Y Center Point
                          cardHeight,  // Image Vertical Height
                          Image_2DBitmaps,       // Image
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
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
                          LCD_COLOR_RED,           // Foreground Color
                          color         // Background Color
                        );
	
}

//This function is a helper for drawing the next cards
int getCard(int card, int number, int dealer){
	
	int x = 0;
	int y = 0;
	
	// These determine the position the cards should be placed
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
	
	//This calls the corresponding function
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

//Function for displaying the proper high score
void highestScore(int myScore){
	if(myScore == 4)
		lcd_draw_image(115, 142, 170, 165, highScore4, LCD_COLOR_RED, LCD_COLOR_BLACK);
  else if(myScore == 5)
		lcd_draw_image(115, 123, 170, 185, highScore5, LCD_COLOR_RED, LCD_COLOR_BLACK);
	else if(myScore == 6)
		lcd_draw_image(115, 148, 170, 202, highScore6, LCD_COLOR_RED, LCD_COLOR_BLACK);
	else if (myScore == 7)
		lcd_draw_image(115, 132, 170, 175, highScore7, LCD_COLOR_RED, LCD_COLOR_BLACK);
	else if (myScore == 8)
		lcd_draw_image(115, 141, 170, 174, highScore8, LCD_COLOR_RED, LCD_COLOR_BLACK);
	else
		lcd_draw_image(115, 142, 170, 165, highScore4, LCD_COLOR_RED, LCD_COLOR_BLACK); // not possible
	
	waitTime(100000);
}

//Function for writing the proper amount of chips to the 8 red LEDS
void setChips(int chips){
	if(chips == 0){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x00);
	}
	if(chips == 1){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x01);
	}
	if(chips == 2){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x03);
	}
	if(chips == 3){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x07);
	}
	if(chips == 4){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x0F);
		}
	if(chips == 5){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x1F);
	}
	if(chips == 6){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x3F);
	}
	if(chips == 7){
		io_expander_write_reg(MCP23017_GPIOA_R, 0x7F);
	}
	if(chips == 8){
		io_expander_write_reg(MCP23017_GPIOA_R, 0xFF);
	}
}


bool checkPause(bool run) {
	// check for space bar to pause/unpause
	char paused;
	if ((paused = fgetc(stdin)) == ' ') { 
		if (run) {
			printf("Paused. Hit space bar to resume...\n");
			run = false;
		} 
		else {
			printf("Running...\n");
			run = true;
		} 
	}
	return run;
}

int 
main(void)
{
	uint8_t button;
uint16_t i;
uint8_t chipCount;
uint8_t playerScore;
uint8_t botScore;
uint8_t playerCards;
uint8_t botCards;
uint16_t genVal;	
uint16_t cardVal;
uint8_t highScore;
bool game_over; // Initialize all variables
bool running;
	
init_hardware();
srand(99); // random seed

printf("Running...\n");
running = true;
	
// get highest chip count and write to screen
eeprom_byte_read(I2C1_BASE, 256, &highScore);
highestScore(highScore);
waitTime(50000);
// infinite game loop	
while (1) {
	
	// set chip count at 4, start game
	chipCount = 4;
	game_over = false;
	
	// display main menu
	lcd_clear_screen(LCD_COLOR_BLACK);
	lcd_draw_image(115, 174, 170, 279, homeScreen, LCD_COLOR_GREEN, LCD_COLOR_BLACK);
	ALERT_BUTTON = false;
	// wait for screen touch, NOTE: TOUCH SCREEN RETURNS FALSE 1s
	while(1){
		
		// check if needs to pause
		running = checkPause(running);
		while (!running){
		  running = checkPause(running);
		}		
		
		
			
			//ALERT_BUTTON = false;
			//printf("handler\n");
			// if any button pressed, reset high score
			button = io_expander_read_reg(MCP23017_GPIOB_R);
			if (!(button & 0x01)) {
				
				eeprom_byte_write(I2C1_BASE, 256, 4);
			}
		
		
		// wait for screen touch
		if (ft6x06_read_td_status() == 2)
			break;
	}
	
	lcd_clear_screen(LCD_COLOR_BLACK);
	setChips(chipCount);
	
  while (!game_over) {
		
		playerScore = 0;
		botScore = 0;
		playerCards = 0;
		botCards = 0;
		
		// check if needs to pause
		running = checkPause(running);
		while (!running){
		  running = checkPause(running);
		}
		
		waitTime(50000);
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

		waitTime(50000);
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
		
		waitTime(50000);
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
		getCard(genVal,1,false); // Place second player card
		
		ALERT_DRAW = false;
		ALERT_STAY = false;
		// wait for user input
		while (1) {	
			// check if needs to pause
		  running = checkPause(running);
		  while (!running){
		    running = checkPause(running);
		  }
			// user inputs draw card
			if (ALERT_DRAW) {
				waitTime(10000);
				// give player random card
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
				getCard(genVal,playerCards-1,false);
				waitTime(50000);
				ALERT_DRAW = false;
			}
			// user inputs stay with current cards
			if (ALERT_STAY) {
				ALERT_STAY = false;
				break;
			}
			// user can have max 4 cards, auto stay if at 4 or bust
			if (playerCards >= 4 || playerScore >= 21) {
				break;
			}
		}
		
		// check if needs to pause
		running = checkPause(running);
		while (!running){
		  running = checkPause(running);
		}
		
		waitTime(50000);
		// make dealer bot pick cards
		while (1) {
			// bot draws until score is at least 17, maximum 4 total cards, or beats player
			if (botScore < 17 && botCards < 4 && (playerScore < 22 || botCards < 2))  {
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
				getCard(genVal,botCards-1,true);
				waitTime(50000);
				// check if needs to pause
		    running = checkPause(running);
		    while (!running){
		      running = checkPause(running);
		    }
			}
			else
				break;
		}
		waitTime(10000);
		
		// turn over, determine winner
    // displays animated message		
		// player wins round
		if ((playerScore > botScore || botScore >= 22)&& playerScore < 22) {
			chipCount++;
			// display win message
			for (i = 120; i < 190; i++)
			  lcd_draw_image(120, 37, i, 35, winHand, LCD_COLOR_GREEN, LCD_COLOR_BLACK);
		}
		// bot wins round
		else {
			if (playerScore < botScore || playerScore >= 22) {
				chipCount--;
				// display loss message
				for (i = 120; i < 190; i++)
				  lcd_draw_image(120, 32, i, 32, loseHand, LCD_COLOR_RED, LCD_COLOR_BLACK);
			}
			// tie
			if (playerScore == botScore) {
				// display tie message
				for (i = 120; i < 190; i++)
				  lcd_draw_image(120, 47, i, 18, push, LCD_COLOR_YELLOW, LCD_COLOR_BLACK);
			}
		}
		setChips(chipCount);
		
		// update high score if passed
		eeprom_byte_read(I2C1_BASE, 256, &highScore);
		if (highScore < chipCount) {
			eeprom_byte_write(I2C1_BASE, 256, chipCount);
		}
		
		waitTime(100000);
		// check if needs to pause
		running = checkPause(running);
		while (!running){
		  running = checkPause(running);
		}
		waitTime(100000);
		
		lcd_clear_screen(LCD_COLOR_BLACK);
		
		// check if game is over
		if (chipCount < 1 || chipCount > 7) {		
			game_over = true;	
		}
	}
	if (chipCount < 1) {
		// show empty chip stack
		io_expander_write_reg(MCP23017_GPIOA_R, 0x00);		
	}
	// player won game 
	if (chipCount > 7) {
		// show full chip stack
		io_expander_write_reg(MCP23017_GPIOA_R, 0xFF);
	}
	// check if needs to pause
	running = checkPause(running);
  while (!running){
		running = checkPause(running);
  }
  // restart game	
}


// won't reach
while(1){};
}



