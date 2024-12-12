#include "../lib/lib.h"

struct interrupt_frame
{
    unsigned int EIP;
    unsigned int CS;        // (this is padded, but who cares, should always be 8 anyway)
    unsigned int EFLAGS;
} __attribute__((packed));


// DIV error: RED message.
void isr_0_c(struct interrupt_frame *frame) {
    char buf1[10];
    char buf2[10];
    char buf3[10];
    intToStr(frame->EIP, buf1);
    intToStr(frame->CS, buf2);
    intToStr(frame->EFLAGS, buf3);
    printString("                                                                                ", 0x40, (char*)(0xB8000+20*160));
    printString("                                                                                ", 0x40, (char*)(0xB8000+21*160));
    printString(buf1, 0x4F, (char*)(0xB8000+20*160));
    printString(buf2, 0x4F, (char*)(0xB8000+20*160+20));
    printString(buf3, 0x4F, (char*)(0xB8000+20*160+40));
    printString("you divided by zero, printed above are: (EIP; CS; EFLAGS)", 0x4F, (char*)(0xB8000+21*160));
    frame->EIP++;
}


// generic exception, not handled yet, MAGENTA error
void isr_generic_c(int int_number) {
    char buf[10];
    intToStr(int_number, buf);
    printString("                                                                                ", 0x50, (char*)(0xB8000+20*160));
    printString("                                                                                ", 0x50, (char*)(0xB8000+21*160));
    printString(buf, 0x5F, (char*)(0xB8000+20*160));
    printString("generic exception, int-number printed above, not handled yet, inf-loop", 0x5F, (char*)(0xB8000+21*160));
    printString("(if int-number = 256 then something bad might've happened)", 0x5F, (char*)(0xB8000+22*160));
    while(1);
}
