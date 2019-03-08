/*
** EPITECH PROJECT, 2019
** list.c
** File description:
** list
*/

#include "nm.h"

list_p *init_list(void)
{
    list_p *list;
    t_list *symbol;

    symbol = malloc(sizeof(*symbol));
    list = malloc(sizeof(*list));
    symbol->name_symbol = NULL;
    symbol->next = NULL;
    symbol->virtual_address = 0;
    symbol->type = ' ';
    list->head = symbol;
    return (list);
}

void print_list(list_p *list)
{
    t_list *symbol = list->head;
    int i = 0;

    while (symbol != NULL && symbol->name_symbol != NULL) {
        if (symbol->virtual_address != 0
        || symbol->type == 't'
        || symbol->type == 'T'
        || symbol->type == 'n') {
            printf("%016lx ", symbol->virtual_address);
            printf("%c ", symbol->type);
            printf("%s\n", symbol->name_symbol);
        } else if (symbol->type == 'w' || symbol->type == 'U')
            printf("\t\t %c %s\n", symbol->type, symbol->name_symbol);
        symbol = symbol->next;
        i++;
    }
}

void init_swap_list(t_swap *swap, list_p *list)
{
    swap->node1 = NULL;
    swap->node2 = NULL;
    swap->prev1 = NULL;
    swap->prev2 = NULL;
    swap->tmp = list->head;
}

void get_swap(t_swap *swap, int index_prev, int index_next)
{
    int i = 0;

    while (swap->tmp != NULL) {
        if (i == index_prev - 1)
            swap->prev1 = swap->tmp;
        if (i == index_prev)
            swap->node1 = swap->tmp;
        if (i == index_next - 1)
            swap->prev2 = swap->tmp;
        if (i == index_next)
            swap->node2 = swap->tmp;
        swap->tmp = swap->tmp->next;
        i++;
    }
}

void swap_list(int index_prev, int index_next, list_p *list)
{
    t_swap swap;

    init_swap_list(&swap, list);
    get_swap(&swap, index_prev, index_next);
    if (swap.node1 != NULL && swap.node2 != NULL) {
        if (swap.prev1 != NULL)
            swap.prev1->next = swap.node2;
        if (swap.prev2 != NULL)
            swap.prev2->next = swap.node1;
        swap.tmp = swap.node1->next;
        swap.node1->next = swap.node2->next;
        swap.node2->next = swap.tmp;
        if (swap.prev1 == NULL)
            list->head = swap.node2;
        else if (swap.prev2 == NULL)
            list->head = swap.node1;
    }
}