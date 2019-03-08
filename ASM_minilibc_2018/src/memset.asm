global memset
section .text

memset:

    push rcx
    xor rcx, rcx

_loop:

    cmp rdx, 0
    je _end
    mov [rdi], sil
    dec rdx
    inc rdi
    jmp _loop

_end:
    mov rax, rdi
    pop rcx
    ret