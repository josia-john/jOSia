#include "lib.h"

void emptyScreen(char* VGA_text) {
    for (int i = 0; i<2*80*25; i++) {
        *(VGA_text+i)=0;
    }
}

void printString(char s[], char color, char* ptr) {

    int i = 0;
    while (s[i]) {
        *(ptr+2*i) = s[i];
        *(ptr+1+2*i) = color;
        i++;
    }    
}

void intToStr(int x, char* buf) {
    if (x == 0) {
        buf[0] = '0';
        buf[1] = 0;
        return;
    }

    char tmp[20];
    int i = 0;
    while (x) {
        tmp[i] = (x%10)+'0';
        x/=10;
        i++;
    }
    int j = i;
    buf[j]=0;
    while (j) {
        j--;
        buf[j]=tmp[i-j-1];
    }
}

void write_byte(unsigned short port, char src) {
    __asm__ volatile (
            "outb %0, %1"
            :
            : "a"(src), "Nd"(port)
        );
}

char read_byte(unsigned short port) {
    char value;
    __asm__ volatile (
        "inb %1, %0"
        : "=a"(value)
        : "Nd"(port)
    );
    return value;
}

void io_wait() {
    read_byte(DUMMY_PORT);
}
