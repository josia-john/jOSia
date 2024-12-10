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

    mov ebx, 0xB8000    ; BASE-address of VGA-text memory
    mov ecx, 0

    cmp eax, 0
    je ret0_loop
    
    crashed_loop:
        mov ax, [KERNEL_CRASHED_MSG + ecx]
        cmp ax, 0
        je inf_loop
        mov [ebx+ecx], ax
        add cx, 2
        jmp crashed_loop

    ret0_loop:
        mov ax, [KERNEL_RET0_MSG + ecx]
        cmp ax, 0
        je inf_loop
        mov [ebx+ecx], ax
        add cx, 2
        jmp ret0_loop

    inf_loop:
    jmp $               ; inf-loop

    KERNEL_CRASHED_MSG:
        db 'K',0xC,'E',0xC,'R',0xC,'N',0xC,'E',0xC,'L',0xC,' ',0xC,'C',0xC,'R',0xC,'A',0xC,'S',0xC,'H',0xC,'E',0xC,'D',0xC,'!',0xC
        db 0,0
    KERNEL_RET0_MSG:
        db 'K',0xC,'E',0xC,'R',0xC,'N',0xC,'E',0xC,'L',0xC,' ',0xC,'R',0xC,'E',0xC,'T',0xC,'U',0xC,'R',0xC,'N',0xC,'E',0xC,'D',0xC,' ',0xC,'0',0xC
        db 0,0