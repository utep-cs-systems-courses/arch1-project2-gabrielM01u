#include <msp430.h>
#include "stateMachine.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  state_machine();
}