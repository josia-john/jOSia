#include "lib.c"

char* VGA_text = (char*)0xB8000;

__attribute__((section(".text.main"))) 
int main() {
    emptyScreen(VGA_text);

    char startup_msg[] = "Kernel started successfully!";
    printString(startup_msg, 0xa, VGA_text);

    // while(1){printString("INF-LOOP", 0xF, VGA_text+320);}
    return 0;
}