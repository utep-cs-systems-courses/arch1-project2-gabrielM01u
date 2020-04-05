#include <msp430.h>
#include "switches.h"

/**
 char sx_down:
   boolean (0 or 1) indicating if a switch is pressed
**/
char s1_down;
char s2_down;
char s3_down;
char s4_down;

void
switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

static char
switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val & ~SWITCHES);
  return p2val;
}

/*  interrupt handler for second board  */
void
switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  s1_down = (p2val & S1) ? 0:1;
  s2_down = (p2val & S2) ? 0:1;
  s3_down = (p2val & S3) ? 0:1;
  s4_down = (p2val & S4) ? 0:1;
  switch_state_changed = 1;
}

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
} 