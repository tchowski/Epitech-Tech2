
global strlen
section .text

strlen:

  push  rcx               ; J'ajoute à élement à la stack
  xor   rcx, rcx          ; XOR {a},{a} : Met à la variable {a} à zéro

_loop:

  cmp   [rdi], byte 0     ; rdi = déplacement ou comparaison / Je check str[i] != '\0'
  jz    _end

  inc   rcx
  inc   rdi
  jmp   _loop

_end:

  mov   rax, rcx          ; MOV {dst},{src}

  pop   rcx
  ret