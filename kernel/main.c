#include "lib/lib.c"
#include "interrupts/interruptHandler.c"

char* VGA_text = (char*)0xB8000;

__attribute__((section(".text.main"))) 
int main() {
    emptyScreen(VGA_text);

    char startup_msg[] = "Kernel started successfully!";
    printString(startup_msg, 0xa, VGA_text);


    // int IDTdesc = initIDT();
    initIDT();

    // char buf[10];
    // intToStr(IDTdesc, buf);
    // printString(buf, 0xf, VGA_text+160);


    // int a = 10;
    // int b = 0;

    // char buf2[10];
    // intToStr(a/b, buf2);
    // printString(buf2, 0xf, VGA_text+160);

    while(1){printString("INF-LOOP", 0xF, VGA_text+320);}
    return 0;
}