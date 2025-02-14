gdt_start:
    ; GDT starts with 8 NULL-bytes
    times 8 db 0x0

gdt_code:
    dw 0xffff    ; segment length, bits 0-15
    dw 0x0    ; segment base, bits 0-15      (shifted by 4??)
    db 0x0       ; segment base, bits 16-23
    db 10011010b ; access byte
    db 11001111b ; flags (4 bits) + segment length, bits 16-19
    db 0x0       ; segment base, bits 24-31

gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

; GDT descriptor
gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
    dd gdt_start ; address (32 bit)

; define some constants for later use
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start