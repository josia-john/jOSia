#include "../lib/lib.h"
#include "keyboard.h"

char* SCANCODE_TO_CHAR = "XX1234567890-=XXqwertyuiop[]XXasdfghjkl;'`X\\zxcvbnm,./X*X ";

int is_ready_for_read() {
    char status = read_byte(KEYBOARD_COMMAND);
    return status & 1;
}

int is_ready_for_write() {
    char status = read_byte(KEYBOARD_COMMAND);
    return (status & 2) >> 1;
}

char read_character_from_keyboard() {
    if (is_ready_for_read()) {
        unsigned char keycode = read_byte(KEYBOARD_DATA);
        if (keycode >= 59) return 0;
        return SCANCODE_TO_CHAR[keycode];
    }
    else {
        return 0;
    }
}