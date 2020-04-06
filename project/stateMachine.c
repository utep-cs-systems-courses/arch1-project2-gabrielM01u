#include "switches.h"
#include "buzzer.h"
#include "led.h"

int state;


void state_machine(int s){
    
    switch(s){
        case 1:
            state_1();
            break;
        case 2:
            state_2();
            enable_green();
            break;
        case 3:
            state_3();
            break;
        case 4:
            state_4();
            break;
        default:
            break;
    }
}
/**
 * States
 **/
void state_1(){
   int timer;
    enable_green();
    led_update();
    buzzer_set_period(2200);
    while(timer++ != 125);
    disable_green();
    buzzer_off();
    led_update();
}

void state_2(){
    int timer;
    enable_red();
    led_update();
    buzzer_set_period(1400);
    while(timer++ != 500);
    disable_red();
    buzzer_off();
    led_update();
}

void state_3(){
    state_1();
    state_2();
}

void state_4(){
    state_2();
    state_3();
}
/**
 * Logic sense
 **/
void logic(char s1_state, char s2_state, char s3_state, char s4_state)
{



}
