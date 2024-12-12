#ifndef __LIB_H_
#define __LIB_H_

#define DUMMY_PORT 0x80     // used for io_wait (dummy write)

void emptyScreen(char* VGA_text);
void printString(char s[], char color, char* ptr);
void intToStr(int x, char* buf);

void write_byte(unsigned short port, char src);
char read_byte(unsigned short port);
void io_wait();

#endif
