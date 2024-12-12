#ifndef __IRQ_H_
#define __IRQ_H_

#define PIC1_CMD		0x20		// IO base address for master PIC
#define PIC2_CMD		0xA0		// IO base address for slave PIC
#define PIC1_DAT		0x21		// IO base address for master PIC
#define PIC2_DAT		0xA1		// IO base address for slave PIC
#define PIC_EOI		0x20		// End-of-interrupt command code

void PIC_sendEOI(char irq);
void PIC_remap(char offset1, char offset2);

#endif