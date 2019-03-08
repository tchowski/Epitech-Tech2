/*
** EPITECH PROJECT, 2019
** init_elf.c
** File description:
** init_elf
*/

#include "strace.h"

int open_file(char *argv)
{
    int fd;

    fd = open(argv, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "strace: Can't stat \'%s\': No such file", argv);
        fprintf(stderr, " or directory\n");
        return (-1);
    }
    return (fd);
}