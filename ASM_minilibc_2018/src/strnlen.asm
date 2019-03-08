
global strnlen
section .text

strnlen:

  push  rcx               ; J'ajoute à élement à la stack
  xor   rcx, rcx          ; XOR {a},{a} : Met à la variable {a} à zéro

_loop:

  cmp   rcx, rsi          ; rsi (argv2) = déplacement ou comparaison
  jz    _end              ; Je check i >= rax

  cmp   [rdi], byte 0     ; rdi (argv1) = déplacement ou comparaison
  jz    _end              ; Je check str[i] != '\0'

  inc   rcx
  inc   rdi
  jmp   _loop

_end:

  mov   rax, rcx          ; MOV {dst},{src}

  pop   rcx
  ret