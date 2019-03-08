/*
** EPITECH PROJECT, 2019
** check_errors.c
** File description:
** check_errors
*/

#include "objdump.h"

int check_elf(Elf64_Ehdr *ehdr)
{
    if ((ehdr->e_ident[0] != 0x7F) || (ehdr->e_ident[1] != 'E')
        || (ehdr->e_ident[2] != 'L') || (ehdr->e_ident[3] != 'F')) {
        return (-1);
    }
    return (0);
}

int check_loop_arguments(int argc, char **argv, int check_error, void *map)
{
    for (int i = 1; i < argc; i++) {
        if (init_elf(argv[i], &map) == -1)
            check_error++;
        else if (run_elf(map, argv[i]) == -1)
            check_error++;
    }
    return (check_error);
}

int check_arguments(int argc, char **argv, int check_error, void *map)
{
    if (argc == 1) {
        if (init_elf_out("a.out", &map) == -1)
            return (1);
        else if (run_elf(map, "a.out") == -1)
            return (1);
    } else if (argc == 2) {
        if (init_elf_out(argv[1], &map) == -1)
            return (1);
        else if (run_elf(map, argv[1]) == -1)
            return (1);
    } else
        return (check_loop_arguments(argc, argv, check_error, &map));
    return (0);
}

bool check_elf_64(Elf64_Ehdr *ehdr)
{
    if (ehdr->e_ident[4] == ELFCLASS64)
        return (true);
    return false;
}