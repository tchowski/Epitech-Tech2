/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils
*/

#include "ftp.h"

bool isnumber(char const *s)
{
    for (size_t i = 0; i < strlen(s); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

bool check_path(char const **argv)
{
    DIR *dir;

    if (argv[2])
        if ((dir = opendir(argv[2])) == NULL) {
            perror(argv[2]);
            return (false);
        }
    return (true);
}

bool check_port(char const **argv)
{
    if (argv[1] && isnumber(argv[1])) {
        return (true);
    } else {
        fprintf(stderr, "Port error: %s\n", argv[1]);
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