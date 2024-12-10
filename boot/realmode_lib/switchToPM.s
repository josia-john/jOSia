[bits 16]
switch_to_pm:
    ; SWITCH TO PROTECTED MODE:
    cli ; 1. disable interrupts
    lgdt [gdt_descriptor] ; 2. load the GDT descriptor
    mov eax, cr0
    or eax, 0x1 ; 3. set 32-bit mode bit in cr0
    mov cr0, eax
    jmp CODE_SEG:init_pm


[bits 32]
init_pm:
    ; SET SEGMENT REGISTERS
    mov ax, DATA_SEG ; 5. update the segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call main       ; call main function of kernel (label in entry.s)

    ; TODO: Good Error Message!
    mov edi, eax
    call PrintInt
    call PrintError     ; should never go here
    jmp $               ; inf-loop
