/*
** EPITECH PROJECT, 2019
** utils2
** File description:
** utils
*/

#include "strace.h"

int print_usage(void)
{
    fprintf(stderr, "strace: must have PROG [ARGS] or -p PID \
    \nTry 'strace -h' for more information.\n");
    return (1);
}