#include "switches.h"
#include "buzzer.h"
#include "led.h"

int state;


void state_machine(){
    while(1){
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
                buzzer_set_period(2000);
        }
    }

}

void state_1(){
    switch(check_switches()){
        case 1:
            state++;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            buzzer_set_period(2000);
    }

}

int check_switches(){
    s1_down? 1:0;
    s2_down? 2:0;
    s3_down? 3:0;
    s4_down? 4:0;
}