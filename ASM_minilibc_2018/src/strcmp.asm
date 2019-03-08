global strcmp
section .text

strcmp:

	push rcx
	xor rcx, rcx      ; compteur de boucle

_loop:
	mov al, [rdi]     ; al: registre low 8 bits
	mov r8b, [rsi]    ; r8b: registre low 8 bits
	cmp al, 0
	je _return
	cmp r8b, 0
	je _return           ; JUMP EQUAL
	cmp al, r8b
	jne _return          ; JUMP NO EQUAL
	inc rdi
	inc rsi
	jmp _loop

_return:
	sub al, r8b       ; last str1[char] - str2[char]
	movsx rax, al     ; déplacement de données (bits différents)
                    ;/ RAX retour valeur de function
	pop rcx
	ret