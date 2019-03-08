/*
** EPITECH PROJECT, 2019
** swap.c
** File description:
** swap
*/

#include "nm.h"

void swap_array_and_list(char **array, char **tmp, list_p *list, int size)
{
    int array_sort = 0;
    int array_to_sort = 0;
    t_display d;

    while (array_sort < size) {
        while (array_to_sort < size) {
            d.prev = delete_under(array[array_to_sort]);
            if (strcmp(tmp[array_sort], d.prev) == 0) {
                swap_list(array_sort, array_to_sort, list);
                d.tmp = array[array_sort];
                array[array_sort] = array[array_to_sort];
                array[array_to_sort] = d.tmp;
            }
            array_to_sort++;
        }
        array_sort++;
        array_to_sort = 0;
    }
}

char **create_tmp_array(int size, char **array)
{
    int i;
    char **tmp;

    i = 0;
    tmp = malloc(sizeof(char *) * size);
    while (i < size) {
        if (array[i] != NULL) {
            tmp[i] = strdup(delete_under(array[i]));
        }
        i++;
    }
    return (tmp);
}

void check_under(char **array, list_p *list, int size)
{
    int array_to_sort;
    t_display d;

    array_to_sort = 0;
    while (array_to_sort < size) {
        if (array_to_sort + 1 < size) {
            d.prev = delete_under(array[array_to_sort]);
            d.next = delete_under(array[array_to_sort + 1]);
            if (strcmp(d.prev, d.next) == 0
            && array[array_to_sort + 1][0] == '_') {
                swap_list(array_to_sort, array_to_sort + 1, list);
                d.tmp = array[array_to_sort];
                array[array_to_sort] = array[array_to_sort + 1];
                array[array_to_sort + 1] = d.tmp;
            }
        }
        array_to_sort++;
    }
}