//
//  Main.c
//  MCLineFollower
//
//  Created by arvindt on 4/15/15.
//
//

#include <stdio.h>
#include <avr/io.h>

int main(void){
    DDRD = 0b00000000;   //setting part D as input part
    DDRB = 0b11111111;   //setting part B as output part
    PORTD = 0b11111111;     //pulling up part D
    int c;
    
    while (1) {
        c = PIND;
        if(c == 0b11111111){
            PORTB = 0b00011010;
        }
        if(c == 0b11111100){   //both sensor low,
            PORTB = 0b00001010;
        }// robot moves forward
        if(c == 0b11111101)
        {     //right sensor high, left sensor low
            PORTB = 0b00001001;  // robot turns right
        }
        if(c == 0b11111110){     //left sensor high, right sensor low
            PORTB = 0b00000110;
        }//robot turns left
    }
    
}

