#ifndef __INTERRUPTS_H_
#define __INTERRUPTS_H_

#define INTERRUPT_ATTRIBUTE 0b10001111      // (1) present; (2) ring 0; (1) 0; (4) 32-bit interrupt gate

int initIDT();


typedef struct __attribute__((packed)) IDT_descriptor_struct {
    unsigned short size;
    unsigned int   offset;
} IDT_descriptor;


typedef struct __attribute__((packed)) IDT_entry_struct {
    unsigned short offset_1;        // offset bits 0..15
    unsigned short selector;        // a code segment selector in GDT or LDT
    unsigned char  zero;            // unused, set to 0
    unsigned char  type_attributes; // gate type, dpl, and p fields
    unsigned short offset_2;        // offset bits 16..31
} IDT_entry;

#endif
