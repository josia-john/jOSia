#include "PIC.h"
#include "../lib/lib.h"


void PIC_remap(char offset1, char offset2) {
    char a1, a2;
	
	a1 = read_byte(PIC1_DAT);                // save masks
	a2 = read_byte(PIC2_DAT);
	
	write_byte(PIC1_CMD, 0x11);                    // starts the initialization sequence (in cascade mode)
	io_wait();
	write_byte(PIC2_CMD, 0x11);
	io_wait();
	write_byte(PIC1_DAT, offset1);                 // ICW2: Master PIC vector offset
	io_wait();
	write_byte(PIC2_DAT, offset2);                 // ICW2: Slave PIC vector offset
	io_wait();
	write_byte(PIC1_DAT, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	io_wait();
	write_byte(PIC2_DAT, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	io_wait();
	
	write_byte(PIC1_DAT, 0x1);                     // ICW4: have the PICs use 8086 mode
	io_wait();
	write_byte(PIC2_DAT, 0x1);
	io_wait();
	
	write_byte(PIC1_DAT, a1);   // restore saved masks.
	write_byte(PIC2_DAT, a2);
}


void PIC_sendEOI(char irq) {
	if(irq >= 8)
		write_byte(PIC2_CMD,PIC_EOI);
	
	write_byte(PIC1_CMD,PIC_EOI);
}


// system timer IRQ
int systimer_tick = 0;
void irq_systimer() {
    printString("        systimer_tick                     ---                              jOSia", 0x70, (char*)(0xB8000+24*160));
    char buf[10];
    intToStr(systimer_tick++, buf);
    printString(buf, 0x70, (char*)(0xB8000+24*160));
}


// IRQ generic handler, BROW error
void irq_generic_c(int irq_number) {
    if (irq_number==0) {
		irq_systimer();
	}
	else {
		char buf[10];
		intToStr(irq_number, buf);
		printString("                                                                                ", 0x60, (char*)(0xB8000+17*160));
		printString("                                                                                ", 0x60, (char*)(0xB8000+18*160));
		printString(buf, 0x6F, (char*)(0xB8000+17*160));
		printString("generic IRQ handler; irq-number printed above;", 0x6F, (char*)(0xB8000+18*160));
    }

    PIC_sendEOI(irq_number);
}


