/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils
*/

#include "mychap.h"

bool isnumber(char const *s)
{
    for (size_t i = 0; i < strlen(s); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

bool check_dns(char **argv)
{
    for (unsigned int i = 0; i < strlen(argv[2]); i++) {
        if ((argv[2][i] < 48 || argv[2][i] > 57) && argv[2][i] != 46)
            return (true);
    }
    return (false);
}

bool check_port(char **argv)
{
    if (argv[4] && isnumber(argv[4])) {
        return (true);
    } else {
        fprintf(stderr, "Port error: %s\n", argv[4]);
        return (false);
    }
}

pid_t check_pid(void)
{
    pid_t pid;
    if ((pid = fork()) == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(84);
    }
    return (pid);
}