[bits 16]
[org 0x7c00] ; bootloader offset

call PrintOK

call BIOSReadDisk

call switch_to_pm


; Include some "libraries"
%include "boot/realmode_lib/IO.s"
%include "boot/realmode_lib/disk.s"
%include "boot/realmode_lib/switchToPM.s"
%include "boot/realmode_lib/gdt.s"

; 
times 510 - ($-$$) db 0
dw 0xaa55

; label for calling main function of the kernel (at address 0x7e00)
main:
