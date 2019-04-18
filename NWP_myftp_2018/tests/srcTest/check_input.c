/*
** EPITECH PROJECT, 2019
** check_input
** File description:
** check_input
*/

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const char *HELP_CMD[] = { "-h", "--help", NULL };

bool check_input(int ac, char **av)
{
    DIR *dir = NULL;

    if (ac != 3) {
        fprintf(stderr, "USAGE: %s [PORT] [PATH]\n", av[0]);
        return (false);
    }
    for (int it = 0; HELP_CMD[it] != NULL; it++)
        if (strcmp(av[1], HELP_CMD[it]) == 0) {
            fprintf(stderr, "USAGE: %s [PORT] [PATH]\n", av[0]);
            return (false);
        }
    dir = opendir(av[2]);
    if (ENOENT == errno) {
        fprintf(stderr, "Error: directory doesn't exist.\n");
        return (false);
    }
    closedir(dir);
    return (true);
}

bool compare(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 == NULL)
        return (true);
    if (s1 == NULL)
        return (false);
    if (s2 == NULL)
        return (false);
    for (size_t it = 0; s1[it] != '\0'; it++)
        if (s1[it] != s2[it])
            return (false);
    for (size_t it = 0; s2[it] != '\0'; it++)
        if (s2[it] != s1[it])
            return (false);
    return (true);
}