#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"

int main(void){

  configureClocks();		
  switch_init();
  enableWDTInterrupts();

  or_sr(0x18);

}