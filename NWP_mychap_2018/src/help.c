/*
** EPITECH PROJECT, 2019
** help.c
** File description:
** help
*/

#include "mychap.h"

int print_usage(void)
{
    printf("./client -t --target -p --port -P --password\n");
    return (84);
}

void print_usage_exit(void)
{
    printf("./client -t --target -p --port -P --password\n");
    exit(84);
}