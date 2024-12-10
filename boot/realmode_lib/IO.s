[bits 16]

PrintChar:
  mov ax, di
  mov ah, 0x0e
  int 0x10
  ret


PrintString:
  mov bx, di

  loop:
    mov di, [bx]
    and di, 0xff
    cmp di, 0
    je done
    call PrintChar
    inc bx
    jmp loop
  
  done:
    ret


PrintNewline:
  mov di, 10      ; print newline
  call PrintChar
  mov di, 13      ; print newline
  call PrintChar
  ret


PrintInt:
    mov cx, 0      ; initialize counter
    mov ax, di    ; read input to eax (dividend (oben))
    mov bx, 10     ; set divisor to 10
    mov dx, 0

    loop1: 
        div bx
        push dx    ; store digit to stack
        mov dx, 0
        inc cx

        cmp ax, 0
        jne loop1

    loop2:
        dec cx
        pop di
        add di, '0'
        call PrintChar

        cmp cx, 0
        jne loop2

    ret


PrintOK:
  mov di, OK_STRING
  call PrintString
  call PrintNewline
  ret
  OK_STRING:
    db 'OK',0


PrintError:
  mov di, ERROR_STRING
  call PrintString
  call PrintNewline
  ret
  ERROR_STRING:
    db 'ERROR',0

