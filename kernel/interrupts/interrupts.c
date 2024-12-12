// TODO: fix includes!!! (all files)
// TODO: refactoring!!
// TODO: more interrupts
// TODO: hardware interrutps (enable with "sti"), program PIC

#include "../lib/lib.h"
#include "interrupts.h"
#include "ISR.h"
#include "PIC.h"

IDT_entry IDT[256];
IDT_descriptor IDT_desc;


void set_ISR(int index, void* offset, unsigned short selector, char attributes) {
    IDT_entry new_entry;

    new_entry.offset_1 = ((unsigned int)offset) & 0xFFFF;
    new_entry.selector = selector;
    new_entry.zero = 0;
    new_entry.type_attributes = attributes;
    new_entry.offset_2 = (((unsigned int)offset)>>16) & 0xFFFF;

    IDT[index] = new_entry;
}


int initIDT() {
    // initialize all interrupts to generic
    for (int i = 0; i<256; i++) {
        set_ISR(i, &isr_generic_asm, 8, INTERRUPT_ATTRIBUTE);
    }

    // ISRs
    set_ISR(0, &isr_0_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(1, &isr_1_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(2, &isr_2_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(3, &isr_3_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(4, &isr_4_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(5, &isr_5_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(6, &isr_6_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(7, &isr_7_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(8, &isr_8_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(9, &isr_9_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(10, &isr_10_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(11, &isr_11_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(12, &isr_12_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(13, &isr_13_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(14, &isr_14_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(15, &isr_15_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(16, &isr_16_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(17, &isr_17_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(18, &isr_18_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(19, &isr_19_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(20, &isr_20_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(21, &isr_21_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(22, &isr_22_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(23, &isr_23_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(24, &isr_24_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(25, &isr_25_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(26, &isr_26_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(27, &isr_27_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(28, &isr_28_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(29, &isr_29_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(30, &isr_30_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(31, &isr_31_asm, 8, INTERRUPT_ATTRIBUTE);

    // IRQs
    set_ISR(0x20 + 0, &irq_0_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 1, &irq_1_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 2, &irq_2_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 3, &irq_3_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 4, &irq_4_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 5, &irq_5_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 6, &irq_6_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 7, &irq_7_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 8, &irq_8_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 9, &irq_9_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 10, &irq_10_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 11, &irq_11_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 12, &irq_12_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 13, &irq_13_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 14, &irq_14_asm, 8, INTERRUPT_ATTRIBUTE);
    set_ISR(0x20 + 15, &irq_15_asm, 8, INTERRUPT_ATTRIBUTE);


    IDT_desc.size = 2047;
    IDT_desc.offset = (int)&IDT;

    __asm__ volatile (
        "lidt %0"                   // Load GDTR
        :                           // output: None
        : "memory"(IDT_desc)        // input IDTdesc
    );


    // Remap IRQs by reprogramming PIC. This will give (0x20 - 0x2F; 32-47)
    PIC_remap(0x20, 0x28);

    // enable interrupts
    __asm__ volatile ("sti");
}



