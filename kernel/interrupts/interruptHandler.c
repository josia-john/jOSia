// TODO: fix includes!!! (all files)
// TODO: refactoring!!
// TODO: more interrupts
// TODO: hardware interrutps (enable with "sti"), program PIC


#include "ISR.c"


struct __attribute__((packed)) IDTDescriptor {
    unsigned short size;
    unsigned int   offset;
};


struct __attribute__((packed)) IDTEntry {
    unsigned short offset_1;        // offset bits 0..15
    unsigned short selector;        // a code segment selector in GDT or LDT
    unsigned char  zero;            // unused, set to 0
    unsigned char  type_attributes; // gate type, dpl, and p fields
    unsigned short offset_2;        // offset bits 16..31
};



struct IDTEntry IDT[256];
struct IDTDescriptor IDTdesc;

int initIDT() {

    struct IDTEntry divbyzero;



    divbyzero.offset_1 = (unsigned short)(unsigned int)&divZero;
    divbyzero.selector = 8;             // TODO
    divbyzero.zero = 0;
    divbyzero.type_attributes = 0b10001111;     // 32 bit exception gate
    divbyzero.offset_2 = 0;

    
    struct IDTEntry default_handler;
    default_handler.offset_1 = (unsigned short)(unsigned int)&defaultIntHandler;
    default_handler.selector = 8;             // TODO
    default_handler.zero = 0;
    default_handler.type_attributes = 0b10001111;     // 32 bit exception gate
    default_handler.offset_2 = 0;

    IDT[0] = divbyzero;
    for (int i = 1; i<256; i++) {
        IDT[i] = default_handler;
    }

    IDTdesc.size = 2047;
    IDTdesc.offset = (int)&IDT;

    __asm__ volatile (
        "lidt %0"      // Load GDTR
        :                 // output: None
        : "memory"(IDTdesc)       // input IDTdesc
    );
}



