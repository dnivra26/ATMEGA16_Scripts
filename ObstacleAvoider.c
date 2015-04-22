//
//  ObstacleAvoider.c
//  MCLineFollower
//
//  Created by arvindt on 4/21/15.
//
//

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void takeReverse(void);
void goForward(int);
void playMusic(void);

int main(void){

    DDRD = 0b00000000;   //setting part D as input part
    DDRB = 0b11111111;   //setting part B as output part
    PORTD = 0b11111111;  //pulling up part D
    int timePeriod = 10;

    int c;

    //PORTB = 0b00001010;

    while(1){
        c = PIND;
        if (c == 0b11111111){   //no obstacle present
            goForward(timePeriod);
        }

        else if (c == 0b11111110){   //obstacle right side
            PORTB = 0b00000110;
        }

        else if (c == 0b11111101){   //obstacle center
            takeReverse();
            PORTB = 0b00000110;
            _delay_ms(500);
        }

        else if (c == 0b11111011){   //obstacle left side
            PORTB = 0b00001001;
        }

        else if (c == 0b11111001){   //obstacle left and center
            takeReverse();
            PORTB = 0b00001001;
            _delay_ms(500);
        }

        else if (c == 0b11111100){   //obstacle center and right
            takeReverse();
            PORTB = 0b00000110;
            _delay_ms(500);
        }

        else if (c == 0b11111010){   //obstacle left and right
            takeReverse();
            PORTB = 0b00000110;
            _delay_ms(1000);
        }

        else if (c == 0b11111000){   //obstacle left center right
            takeReverse();
            PORTB = 0b00000110;
            _delay_ms(1000);
        }
    }
}


void takeReverse(void){
    int DELAY = 500;
    PORTB = 0b00000101;
    _delay_ms(DELAY);
}

void goForward(int timePeriod){
    PORTB = 0b00001010;
}
