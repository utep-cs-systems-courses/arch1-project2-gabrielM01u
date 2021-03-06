#ifndef switches_included
#define switches_included

#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3
#define SWITCHES (S1|S2|S3|S4)

void switch_init();
void switch_interrupt_handler();
static char switch_update_interrupt_sense();

extern char s1_down;
extern char s2_down;
extern char s3_down;
extern char s4_down;

extern char switch_state_changed;


#endif