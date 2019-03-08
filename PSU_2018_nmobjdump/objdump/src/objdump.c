/*
** EPITECH PROJECT, 2019
** objdump.c
** File description:
** objdump
*/

#include "objdump.h"

int print_name_flag(size_t *flag)
{
    if ((*flag & BFD_NO_FLAGS) != 0) {
        printf("NO_FLAGS");
        return (0);
    }
    if ((*flag & HAS_SYMS) != 0) {
        printf("HAS_SYMS");
        *flag -= HAS_SYMS;
        return (0);
    }
    if ((*flag & DYNAMIC) != 0) {
        printf("DYNAMIC");
        *flag -= DYNAMIC;
        return (0);
    }
    if ((*flag & D_PAGED) != 0) {
        printf("D_PAGED");
        *flag -= D_PAGED;
        return (0);
    }
    return (1);
}

void loop_flag(size_t flag)
{
    int check_return;

    check_return = 0;
    for (int i = 0; i < 4; i++) {
        check_return = print_name_flag(&flag);
        if (i + 1 < 4 && check_return == 0 && flag != 0)
            printf(", ");
    }
}

size_t print_flags_architecture(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, t_sym *s)
{
    size_t flag;
    (void)shdr;

    flag = BFD_NO_FLAGS;
    if (ehdr->e_type == ET_EXEC)
        flag |= EXEC_P;
    if (ehdr->e_type == ET_DYN)
        flag += DYNAMIC + D_PAGED;
    if (ehdr->e_type == ET_REL)
        flag |= HAS_RELOC;
    if (s->tabsize > 0) {
        flag |= HAS_SYMS;
    }
    printf("%010ld:\n", flag);
    return (flag);
}

void check_architecure(Elf64_Ehdr *ehdr)
{
    if (ehdr->e_machine == 62)
        printf("architecture: i386:x86-64, flags ");
}

void objdump_header(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, char *strtab, t_sym *s)
{
    Elf64_Addr address_header;
    size_t flag;

    flag = BFD_NO_FLAGS;
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (strcmp(NAME, ".text") == 0)
            address_header = shdr[i].sh_addr;
    }
    check_architecure(ehdr);
    flag = print_flags_architecture(ehdr, shdr, s);
    loop_flag(flag);
    printf("\nstart address %018ld\n\n", address_header);
}