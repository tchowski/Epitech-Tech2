/*
** EPITECH PROJECT, 2019
** list2.c
** File description:
** list2
*/

#include "nm.h"

int get_size_list(list_p *list)
{
    int i;
    t_list *symbol;

    symbol = list->head;
    for (i = 0; symbol != NULL; i++) {
        symbol = symbol->next;
    }
    return (i - 1);
}

void print_all_list(list_p *list)
{
    t_list *symbol = list->head;

    while (symbol) {
        if (symbol->name_symbol)
            printf("%s\n", symbol->name_symbol);
        symbol = symbol->next;
    }
}