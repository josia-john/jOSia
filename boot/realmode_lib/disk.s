BIOSReadDisk:         ; EDI: disk address (sector), ESI ram address
    mov di, DISK_STRING
    call PrintString

    xor eax, eax
    mov ds, ax          ; set data-segment to 0
    mov si, DAPACK		; address of "disk address packet"
    mov ah, 0x42		; Extended Disk Read
    int 0x13
    jc diskError

    call PrintOK

    ret

    align 16
    DAPACK:
        dw 0x10             ; always 0x10 (size of packet)
        dw 0x20              ; Number of sectors to load
        dw 0, 0x7e00 >> 4   ; segment:offset where kernel loaded to.
        dq 1                ; Read from sector 1 (0 indexed) (0x200), that's where the kernel starts.


diskError:
    mov al, ah          ; get error-code from ah to al
    mov ah, 0
    mov di, ax          ; load error-code as argument
    call PrintInt

    mov di, ' '
    call PrintChar

    call PrintError
    ret

    
DISK_STRING:
    db 'LOADING KERNEL FROM DISK... ',0