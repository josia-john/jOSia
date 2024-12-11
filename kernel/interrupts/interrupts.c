// TODO: fix includes!!! (all files)
// TODO: refactoring!!
// TODO: more interrupts
// TODO: hardware interrutps (enable with "sti"), program PIC

#include "../lib/lib.h"
#include "interrupts.h"
#include "ISR.h"

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

    set_ISR(0, &div_zero, 8, INTERRUPT_ATTRIBUTE);

    for (int i = 1; i<256; i++) {
        set_ISR(i, &default_handler, 8, INTERRUPT_ATTRIBUTE);
    }

    IDT_desc.size = 2047;
    IDT_desc.offset = (int)&IDT;

    __asm__ volatile (
        "lidt %0"                   // Load GDTR
        :                           // output: None
        : "memory"(IDT_desc)        // input IDTdesc
    );
}



