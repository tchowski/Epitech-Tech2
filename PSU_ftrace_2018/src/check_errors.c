/*
** EPITECH PROJECT, 2019
** check_errors.c
** File description:
** check_errors
*/

#include "strace.h"
#include <elf.h>
#include <errno.h>

int check_elf(Elf64_Ehdr *ehdr)
{
    if ((ehdr->e_ident[0] != 0x7F) || (ehdr->e_ident[1] != 'E')
    || (ehdr->e_ident[2] != 'L') || (ehdr->e_ident[3] != 'F')) {
        return (-1);
    }
    return (0);
}

int check_pid(pid_t *pid)
{
    *pid = fork();
    if (*pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return (-1);
    }
    return (0);
}

static int check_flag_p(char **argv)
{
    if (argv[2] != NULL)
        return (run_ptrace_p(atoi(argv[2])));
    else
        return (print_usage());
    return (0);
}

static int check_flag_s(char **argv, char **envp)
{
    int return_code;

    if (argv[2] != NULL) {
        if (open_file(argv[2]) == -1)
            return (1);
        return_code = strace(argv, envp, argv[2]);
        return_code == -1 ? exit(1) : exit(return_code);
    } else
        return (print_usage());
    return (0);
}

int check_arguments(int argc, char **argv, char **envp)
{
    int fd;
    int return_code;

    if (argc <= 3 && argc > 1) {
        if (strcmp(argv[1], "--help") == 0)
            return (print_usage());
        if (strcmp(argv[1], "-s") == 0)
            return (check_flag_s(argv, envp));
        if (strcmp(argv[1], "-p") == 0)
            return (check_flag_p(argv));
        if ((fd = open_file(argv[1]) == -1))
            return (1);
        if (argc == 2) {
            return_code = strace(argv, envp, argv[1]);
            return_code == -1 ? exit(1) : exit(return_code);
        } else
            return (print_usage());
    }
    return (print_usage());
}