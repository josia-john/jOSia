#include "../lib/lib.h"


void div_zero() {
    printString("                                                                                ", 0xCC, (char*)0xB8000);
    printString("                                                                                ", 0xCC, (char*)(0xB8000+160));
    printString("you divided by zero!!", 0xC, (char*)0xB8000);
    while(1);
}


void default_handler() {
    printString("                                                                                ", 0xCC, (char*)0xB8000);
    printString("                                                                                ", 0xCC, (char*)(0xB8000+160));
    printString("you caused some exception (not div by zero)!!", 0xC, (char*)0xB8000);
    while(1);
}