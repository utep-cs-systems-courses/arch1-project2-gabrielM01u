#include "switches.h"
#include "buzzer.h"
#include "led.h"

int state;


void state_machine(){
    
    switch(state){
        case 1:
            state_1();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void state_1(){
    switch(check_switches()){
        int timer = 0;
        case 1:
            enable_green();
            led_update();
            buzzer_set_period(2200);
            while(timer++ != 125);
            disable_green();
            led_update();
            state++;
            break;
        case 2:
            enable_red();
            led_update();
            buzzer_set_period(1400);
            while(timer++ != 500);
            disable_red();
            led_update();
            state = 0;
            break;
        case 3:
            break;
        case 4:
            break;
    }

}

/**
 * int check_switches():
 *      If a single switch is pressed, will return
 *      the number of that switch. 
 **/
int check_switches(){
    if(s1_down) return 1;
    else if(s2_down) return 2;
    else if(s3_down) return 3;
    else if(s4_down) return 4;
    else return 0;
}