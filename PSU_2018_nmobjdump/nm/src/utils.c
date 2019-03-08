/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "nm.h"

static int my_compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void sort(char **arr[], int n)
{
    qsort(*arr, n, sizeof(const char *), my_compare);
}

static void my_free(char *tab)
{
    if (tab != NULL)
        free(tab);
    return;
}

void free_tabs(char **tab, int size)
{
    int i;

    i = 0;
    while (i < size) {
        if (tab[i] != NULL)
            my_free(tab[i]);
        i++;
    }
    free(tab);
}

void print_tabs(char **array, int size)
{
    int i;

    i = 0;
    while (i < size) {
        printf("%s\n", array[i]);
        i++;
    }
    return;
}