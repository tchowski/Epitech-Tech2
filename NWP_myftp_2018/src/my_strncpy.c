/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** strncpy
*/

#include "ftp.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int k = 0;

    while (k < n && src[k]) {
        dest[k] = src[k];
        k++;
    }
    if (k <= n)
        dest[k] = 0;
    return (dest);
}
