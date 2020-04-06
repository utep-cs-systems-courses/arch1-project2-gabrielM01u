	.arch msp430g2553
	.p2align 1,0


;;state machine
    .text
jt: .word default
    .word case_1
    .word case_2
    .word case_3
    .word case_4

    .text
    .global state_machine
state_machine:

    cmp #4, r12
    jnc default

    mov jt(r12), r0

case_1:
    call #state_1
    jmp exit
case_2:
    call #state_2
    jmp exit
case_3:
    call #state_3
    jmp exit
case_4:
    call #state_4
    jmp exit
default:
    jmp exit
exit:
    ret


    .text
state_1:
    call #enable_green
    call #led_update
    mov 2200, r12
    call #buzzer_set_period
    