global memcpy
section .text

;void *memcpy(void *str1, const void *str2, size_t n)

memcpy:

    push rcx
    xor rcx, rcx

_loop:

    cmp rdx, 0
    je _end
    mov al, [rsi]
    mov [rdi], al
    dec rdx
    inc rdi
    inc rsi
    jmp _loop

_end:
    mov rax, rdi
    pop rcx
    ret