/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** errors
*/

#include "mychap.h"

void my_perror(const char *str)
{
    perror(str);
    exit(84);
}