extern isr_generic_c
extern irq_generic_c


; CUSTOM ----------------------------------------------------------------------
; If we need to pass pointer to stack elements (EIP; for continuing)

extern isr_0_c
global isr_0_asm
isr_0_asm:
    pushad
    cld             ; SYSTEM-V Calling convention?
    mov eax, esp
    add eax, 32
    push eax        ; Push address of interrupt_frame as argument
    call isr_0_c    ; Call ISR
    pop eax
    popad
    iret


; JUST PUSH NUMBER TO STACK ---------------------------------------------------

global isr_1_asm
isr_1_asm:
    pushad
    cld
    push 1
    call isr_generic_c
    pop eax
    popad
    iret

global isr_2_asm
isr_2_asm:
    pushad
    cld
    push 2
    call isr_generic_c
    pop eax
    popad
    iret

global isr_3_asm
isr_3_asm:
    pushad
    cld
    push 3
    call isr_generic_c
    pop eax
    popad
    iret

global isr_4_asm
isr_4_asm:
    pushad
    cld
    push 4
    call isr_generic_c
    pop eax
    popad
    iret

global isr_5_asm
isr_5_asm:
    pushad
    cld
    push 5
    call isr_generic_c
    pop eax
    popad
    iret

global isr_6_asm
isr_6_asm:
    pushad
    cld
    push 6
    call isr_generic_c
    pop eax
    popad
    iret

global isr_7_asm
isr_7_asm:
    pushad
    cld
    push 7
    call isr_generic_c
    pop eax
    popad
    iret

global isr_8_asm
isr_8_asm:
    pushad
    cld
    push 8
    call isr_generic_c
    pop eax
    popad
    iret

global isr_9_asm
isr_9_asm:
    pushad
    cld
    push 9
    call isr_generic_c
    pop eax
    popad
    iret

global isr_10_asm
isr_10_asm:
    pushad
    cld
    push 10
    call isr_generic_c
    pop eax
    popad
    iret

global isr_11_asm
isr_11_asm:
    pushad
    cld
    push 11
    call isr_generic_c
    pop eax
    popad
    iret

global isr_12_asm
isr_12_asm:
    pushad
    cld
    push 12
    call isr_generic_c
    pop eax
    popad
    iret

global isr_13_asm
isr_13_asm:
    pushad
    cld
    push 13
    call isr_generic_c
    pop eax
    popad
    iret

global isr_14_asm
isr_14_asm:
    pushad
    cld
    push 14
    call isr_generic_c
    pop eax
    popad
    iret

global isr_15_asm
isr_15_asm:
    pushad
    cld
    push 15
    call isr_generic_c
    pop eax
    popad
    iret

global isr_16_asm
isr_16_asm:
    pushad
    cld
    push 16
    call isr_generic_c
    pop eax
    popad
    iret

global isr_17_asm
isr_17_asm:
    pushad
    cld
    push 17
    call isr_generic_c
    pop eax
    popad
    iret

global isr_18_asm
isr_18_asm:
    pushad
    cld
    push 18
    call isr_generic_c
    pop eax
    popad
    iret

global isr_19_asm
isr_19_asm:
    pushad
    cld
    push 19
    call isr_generic_c
    pop eax
    popad
    iret

global isr_20_asm
isr_20_asm:
    pushad
    cld
    push 20
    call isr_generic_c
    pop eax
    popad
    iret

global isr_21_asm
isr_21_asm:
    pushad
    cld
    push 21
    call isr_generic_c
    pop eax
    popad
    iret

global isr_22_asm
isr_22_asm:
    pushad
    cld
    push 22
    call isr_generic_c
    pop eax
    popad
    iret

global isr_23_asm
isr_23_asm:
    pushad
    cld
    push 23
    call isr_generic_c
    pop eax
    popad
    iret

global isr_24_asm
isr_24_asm:
    pushad
    cld
    push 24
    call isr_generic_c
    pop eax
    popad
    iret

global isr_25_asm
isr_25_asm:
    pushad
    cld
    push 25
    call isr_generic_c
    pop eax
    popad
    iret

global isr_26_asm
isr_26_asm:
    pushad
    cld
    push 26
    call isr_generic_c
    pop eax
    popad
    iret

global isr_27_asm
isr_27_asm:
    pushad
    cld
    push 27
    call isr_generic_c
    pop eax
    popad
    iret

global isr_28_asm
isr_28_asm:
    pushad
    cld
    push 28
    call isr_generic_c
    pop eax
    popad
    iret

global isr_29_asm
isr_29_asm:
    pushad
    cld
    push 29
    call isr_generic_c
    pop eax
    popad
    iret

global isr_30_asm
isr_30_asm:
    pushad
    cld
    push 30
    call isr_generic_c
    pop eax
    popad
    iret

global isr_31_asm
isr_31_asm:
    pushad
    cld
    push 31
    call isr_generic_c
    pop eax
    popad
    iret


; IRQs ------------------------------------------------------------------------

global irq_0_asm
irq_0_asm:
    pushad
    cld
    push 0
    call irq_generic_c
    pop eax
    popad
    iret

global irq_1_asm
irq_1_asm:
    pushad
    cld
    push 1
    call irq_generic_c
    pop eax
    popad
    iret

global irq_2_asm
irq_2_asm:
    pushad
    cld
    push 2
    call irq_generic_c
    pop eax
    popad
    iret

global irq_3_asm
irq_3_asm:
    pushad
    cld
    push 3
    call irq_generic_c
    pop eax
    popad
    iret

global irq_4_asm
irq_4_asm:
    pushad
    cld
    push 4
    call irq_generic_c
    pop eax
    popad
    iret

global irq_5_asm
irq_5_asm:
    pushad
    cld
    push 5
    call irq_generic_c
    pop eax
    popad
    iret

global irq_6_asm
irq_6_asm:
    pushad
    cld
    push 6
    call irq_generic_c
    pop eax
    popad
    iret

global irq_7_asm
irq_7_asm:
    pushad
    cld
    push 7
    call irq_generic_c
    pop eax
    popad
    iret

global irq_8_asm
irq_8_asm:
    pushad
    cld
    push 8
    call irq_generic_c
    pop eax
    popad
    iret

global irq_9_asm
irq_9_asm:
    pushad
    cld
    push 9
    call irq_generic_c
    pop eax
    popad
    iret

global irq_10_asm
irq_10_asm:
    pushad
    cld
    push 10
    call irq_generic_c
    pop eax
    popad
    iret

global irq_11_asm
irq_11_asm:
    pushad
    cld
    push 11
    call irq_generic_c
    pop eax
    popad
    iret

global irq_12_asm
irq_12_asm:
    pushad
    cld
    push 12
    call irq_generic_c
    pop eax
    popad
    iret

global irq_13_asm
irq_13_asm:
    pushad
    cld
    push 13
    call irq_generic_c
    pop eax
    popad
    iret

global irq_14_asm
irq_14_asm:
    pushad
    cld
    push 14
    call irq_generic_c
    pop eax
    popad
    iret

global irq_15_asm
irq_15_asm:
    pushad
    cld
    push 15
    call irq_generic_c
    pop eax
    popad
    iret


; ALL OTHER -------------------------------------------------------------------

global isr_generic_asm
isr_generic_asm:
    pushad
    cld
    push 256
    call isr_generic_c
    popad
    iret
