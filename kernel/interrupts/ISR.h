#ifndef __ISR_H_
#define __ISR_H_

// ISRs (from 0-31)
void isr_0_asm();
void isr_1_asm();
void isr_2_asm();
void isr_3_asm();
void isr_4_asm();
void isr_5_asm();
void isr_6_asm();
void isr_7_asm();
void isr_8_asm();
void isr_9_asm();
void isr_10_asm();
void isr_11_asm();
void isr_12_asm();
void isr_13_asm();
void isr_14_asm();
void isr_15_asm();
void isr_16_asm();
void isr_17_asm();
void isr_18_asm();
void isr_19_asm();
void isr_20_asm();
void isr_21_asm();
void isr_22_asm();
void isr_23_asm();
void isr_24_asm();
void isr_25_asm();
void isr_26_asm();
void isr_27_asm();
void isr_28_asm();
void isr_29_asm();
void isr_30_asm();
void isr_31_asm();

// IRQs (from PIC)
void irq_0_asm();
void irq_1_asm();
void irq_2_asm();
void irq_3_asm();
void irq_4_asm();
void irq_5_asm();
void irq_6_asm();
void irq_7_asm();
void irq_8_asm();
void irq_9_asm();
void irq_10_asm();
void irq_11_asm();
void irq_12_asm();
void irq_13_asm();
void irq_14_asm();
void irq_15_asm();

// All others, shouldn't happen though... (has a note in ISR.c:isr_generic_c(), 256 set in assembly)
void isr_generic_asm();

#endif
