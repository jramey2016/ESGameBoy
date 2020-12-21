/*
 * LCD application.c
 *
 * Created: 11/10/2020 10:00:05 PM
 * Author : Jordan R
 */ 

#include "Lcdlbr/lcd.h"
////////////////////////////////////////////////Library Accreditation////////////////////////////
// The open-sourced library can be found here: https://github.com/sarful/how-to-add-lcd-library-in-avr-studio-avr-microcontroller-tutorial
//Credit to: Sarful Hassan / Peter Fluery
#ifndef F_CPU
#define F_CPU 10000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

////////////////////////////////////////////////////////////////////////Game 1///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void start_game(){ //Game #1 "Spider Crawl" race to the finish line to level up complete 5 levels to beat the game.
	int characterX = 0; //initializing these values to zero and will help coordinate where the character are on the screen.
	int characterY = 0;

	int enemy_X1 = 15; //initializing these values to zero and will help coordinate where the enemy are on the screen.
	int enemy_Y1 = 0;
	
	int enemy_X2 = 12;
	int enemy_Y2 = 1;
	
	int enemy_X3 = 25;
	int enemy_Y3 = 0;
	
	int enemy_X4 = 31;
	int enemy_Y4 = 1;
	
	int lvl_counter = 0; //counting the level that you are on.
	
	int enemy_speed_lvl1 = 250; //initial speed of the enemy.
	
	lcd_clrscr();
	lcd_gotoxy(3,0);
	lcd_puts("Level 1");
	_delay_ms(1500);
	
	while(1){ //starting the game
		
	 if(!(PINB & (1<<PINB3))){ //control structure to make the sprite go to the right or positive x direction once button is pressed.
		 characterX = characterX + 1;
		 
		 lcd_clrscr();
		 lcd_gotoxy(characterX,characterY);
		 lcd_puts("#");
	 }
	 
	 if(!(PINB & (1<< PINB2))){ //control structure to make the sprite go left or in the negative x direction once the button is pressed.
		 characterX = characterX - 1; 
		 if(characterX < 0){ //Can return to the upper half
			 characterX = characterX + 1;
		 }
		 lcd_clrscr();
		 lcd_gotoxy(characterX,characterY);
		 lcd_puts("#");
	 }
	 
	 if(!(PINB & (1<< PINB1))){ //control structure to make the sprite go down or the negative y direction once the button is pressed.
		 characterY = characterY + 1;
		 if(characterY > 2){ //Access to the lower half the screen
			 characterX = characterX + 16;
			 characterY = 0;
		 }
		 lcd_clrscr();
		 lcd_gotoxy(characterX,characterY);
		 lcd_puts("#");
	 }
	 
	if(!(PINB & (1 <<PINB0))){ //control structure to make the sprite go up or in the positive y direction once the button is pressed.
		 characterY = characterY - 1;
		 if(characterY < 0){ //Boundary control
			 characterX = characterX - 16;
			 characterY = 1;
		 }
		 
		 lcd_clrscr();
		 lcd_gotoxy(characterX,characterY);
		 lcd_puts("#");

	 }
	 
	 if(enemy_X1 < 0){ //Re-spawning enemy once they go off screen.
		 enemy_X1 = 15;
	 }
	 if(enemy_X2 < 0){//Re-spawning enemy once they go off screen.
		 enemy_X2 = 13;
	 }
	 
	 lcd_clrscr();
	 
	 lcd_gotoxy(characterX,characterY); //starting coordinates of the sprite.
	 lcd_puts("#"); //character sprite
	 
	 lcd_gotoxy(enemy_X1,enemy_Y1); //starting coordinates of the enemy.
	 lcd_puts("|"); //enemy sprite
	 
	 lcd_gotoxy(enemy_X2,enemy_Y2); //starting coordinates of the second enemy.
	 lcd_puts("|"); //enemy sprite
	 
	 lcd_gotoxy(enemy_X3,enemy_Y3);
	 lcd_puts("|");
	 
	 lcd_gotoxy(enemy_X4,enemy_Y4);
	 lcd_puts("|");
	 
	 if(characterX == 15 || characterX == 31){ //Once the character reaches the end of the screen it will consult to a level up (5 levels before a win).
	
		lvl_counter = lvl_counter + 1; //5 levels in the game.
		 	
	    if(lvl_counter >= 5){
				  lcd_clrscr();
				  lcd_gotoxy(3,0);
				  lcd_puts("You Win!"); //message letting the player know that they won.
				  _delay_ms(3000);
				  main(); //Restart the game
			}
			lcd_clrscr();
		 	lcd_gotoxy(3,0);
		 	lcd_puts("Level Up!");
			
		 	_delay_ms(1500);
			 
			characterX = 0; //reset the character coordinates
			characterY = 0; 
			
		if(lvl_counter == 1){ //change the level layout.
			lcd_clrscr();
			lcd_gotoxy(3,0);
			lcd_puts("Level 2");
			_delay_ms(2000);
			
			enemy_X1 = 10; //reset enemy at different coordinates.
			enemy_Y1 = 0;
			enemy_X2 = 14; //reset enemy at different coordinates.
			enemy_Y2 = 1;
			enemy_X3 = 31;
			enemy_Y3 = 0;
			enemy_X4 = 23;
			enemy_Y4 = 1;
		}
		if(lvl_counter == 2){ //change the level layout.
			lcd_clrscr();
			lcd_gotoxy(3,0);
			lcd_puts("Level 3");
			_delay_ms(2000);
			
			enemy_X1 = 14; //reset enemy at different coordinates.
			enemy_Y1 = 0;
			enemy_X2 = 6; //reset enemy at different coordinates.
			enemy_Y2 = 1;
			enemy_X3 = 22;
			enemy_Y3 = 0;
			enemy_X4 = 30;
			enemy_Y4 = 1;
		}
		if(lvl_counter == 3){ //change the level layout.
			lcd_clrscr();
			lcd_gotoxy(3,0);
			lcd_puts("Level 4");
			_delay_ms(2000);
			
			enemy_X1 = 5; //reset enemy at different coordinates.
			enemy_Y1 = 0;
			enemy_X2 = 10; //reset enemy at different coordinates.
			enemy_Y2 = 1;
			enemy_X3 = 24;
			enemy_Y3 = 0;
			enemy_X4 = 27;
			enemy_Y4 = 1;
		}
		if(lvl_counter == 4){ //change level layout
			lcd_clrscr();
			lcd_gotoxy(3,0);
			lcd_puts("Level 5");
			_delay_ms(2000);
			
			enemy_X1 = 7; //reset enemy at different coordinates.
			enemy_Y1 = 0;
			enemy_X2 = 3; //reset enemy at different coordinates.
			enemy_Y2 = 1;
			enemy_X3 = 17;
			enemy_Y3 = 0;
			enemy_X4 = 29;
			enemy_Y4 = 1;
		}
	 }
	 
	 
	 if((characterX == enemy_X1 && characterY == enemy_Y1) || (characterX == enemy_X2 && characterY == enemy_Y2) || (characterX == enemy_X3 && characterY == enemy_Y3) || (characterX == enemy_X4 && characterY == enemy_Y4)){ //hit box for when the character if it collides with the enemy.
		   lcd_clrscr();
		   lcd_gotoxy(3,0);
		   lcd_puts("Game Over!"); //game ending message
		   _delay_ms(4000);
		   main(); //call main to restart the game
	 }
	 if(enemy_X3 < 17){
		 enemy_X3 = 31;
	 }
	 if(enemy_X4 < 17){
		 enemy_X4 = 31;
	 }
	 
	 _delay_ms(enemy_speed_lvl1); //controlling the speed that an enemy moves.
	 enemy_X1 = enemy_X1 - 1;
	 enemy_X2 = enemy_X2 - 1;
	 enemy_X3 = enemy_X3 - 1;
	 enemy_X4 = enemy_X4 - 1;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////Game 2///////////////////////////////////////////////////////////////////////////////////////////////////////

void start_game2(){ //Hurdles fairly simple game jump over the hurdles and try to get to 50.
	int character_X2 = 18; //character initial starting space.
	int character_Y2 = 1;
	
	int character_X3 = 18; // character head
	int character_Y3 = 0;
	
	int Hurdle_X = 32;
	int Hurdle_Y = 1;
	
	int player_score = 0;
	int score_X = 3;
	int score_Y = 0;

	while(1){
		lcd_clrscr();
		lcd_gotoxy(character_X2,character_Y2); //character body
		lcd_puts("!");
		
		lcd_gotoxy(character_X3,character_Y3); //character head
		lcd_puts("o");
		
		lcd_gotoxy(Hurdle_X,Hurdle_Y); //hurdle
		lcd_puts("/");
		
		
		lcd_gotoxy(score_X,score_Y);
		
		
		if(!(PINB & (1 <<PINB1))){ 
			//jumping action and to make sure the hurtle still proceeds to move
			character_Y2 = character_Y2 - 1;
			character_X3 = character_X3 - 16;
			lcd_clrscr();
			lcd_gotoxy(character_X2,character_Y2);
			lcd_puts("!");
			lcd_gotoxy(character_X3,1);
			lcd_puts("o");
			lcd_gotoxy(Hurdle_X - 1,Hurdle_Y);
			lcd_puts("/");
			_delay_ms(300);
			
			
			//return character to initial spot
				
			character_Y2 = character_Y2 + 1;	
			character_X3 = character_X3 + 16;
			lcd_clrscr();
			lcd_gotoxy(character_X2,character_Y2);
			
			if(Hurdle_X < 21){
				Hurdle_X = 15;
				player_score = player_score + 1;
			}
			if(player_score == 10){ //score reads out in increments of 10
				lcd_clrscr();
				lcd_gotoxy(3,0);
				lcd_puts("Score: 10");
				_delay_ms(500);
			}
			if(player_score == 20){
				lcd_clrscr();
				lcd_gotoxy(3,0);
				lcd_puts("Score: 20");
				_delay_ms(500);
			}
			if(player_score == 30){
				lcd_clrscr();
				lcd_gotoxy(3,0);
				lcd_puts("Score: 30");
				_delay_ms(500);
			}
			if(player_score == 40){
				lcd_clrscr();
				lcd_gotoxy(3,0);
				lcd_puts("Score: 40");
				_delay_ms(500);
			}
			if(player_score == 50){ //score has reached 50 return to menu.
				lcd_clrscr();
				lcd_gotoxy(3,0);
				lcd_puts("Score: 50");
				lcd_gotoxy(3,1);
				lcd_puts("You Win!");
				_delay_ms(500);
				main();
			}
		}
	    
		if(Hurdle_X < 16){ //wrap the hurtle to the other side of the screen 
			Hurdle_X = 32;
		}
	
		if((character_X2 == Hurdle_X)){ //Logic for hit box
			lcd_clrscr();
			lcd_gotoxy(3,0);
			lcd_puts("Game Over!");
			_delay_ms(3000);
			main();
		}
		
		_delay_ms(250);
		Hurdle_X = Hurdle_X - 1; //keep hurtle moving
	
		
	}
}




int main(void)
{
	
	lcd_init(LCD_DISP_ON_CURSOR); 
	lcd_clrscr(); //clear screen
	lcd_puts("ES BOY 2020!"); //starting message 1st row
	lcd_gotoxy(0,1);
	lcd_puts("Up:Spider Crawl");
	lcd_gotoxy(16,0);
	lcd_puts("Down:Hurdles");
    
	DDRB &= ~(1<<PINB0); //Setting pins as inputs for the buttons
	DDRB &= ~(1<<PINB1);
	DDRB &= ~(1<<PINB2);
	DDRB &= ~(1<<PINB3);
	
	PORTB |= (1<< PINB0); //Internal pull-ups for the pins
	PORTB |= (1<< PINB1);
	PORTB |= (1<< PINB2);
	PORTB |= (1<< PINB3);
	
    while (1) 
    { 
		//if(!(PINB & (1<< PINB3))){
			//start_game(); // "Right" button pressed starting the game.
		//}
		
		//if(!(PINB & (1<< PINB2))){
			//start_game(); // "Left" button pressed starting the second game.
		//}
		
	   if(!(PINB & (1<<PINB1))){
			 start_game2(); //"Down" button pressed starting the game.
		 }
		 
	  if(!(PINB & (1<<PINB0))){
			start_game(); //"Up" button pressed starting the game.
		}
	}
}


