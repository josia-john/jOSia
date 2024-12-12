#include "lib/lib.h"
#include "interrupts/interrupts.h"

char* VGA_text = (char*)0xB8000;

__attribute__((section(".text.main"))) 
int main() {
    emptyScreen(VGA_text);

    char startup_msg[] = "Kernel started successfully!";
    printString(startup_msg, 0xa, VGA_text);

    initIDT();

    

    // __asm__ volatile ("int $0x21");

    // int x = 3/0;
    // char buf[10];
    // intToStr(x, buf);
    // printString(buf, 0xF, VGA_text+160);

    
    while(1){printString("INF-LOOP", 0xF, VGA_text+320);}
    return 0;
}