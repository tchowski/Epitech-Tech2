/*
** EPITECH PROJECT, 2019
** quick_sort
** File description:
** quick_sort
*/

#include "nm.h"

bool compare_string(char *string1, char *string2)
{
    int i;

    for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++) {
        if (string1[i] == '_' || string2[i] == ' ')
            continue;
        if (string1[i] > string2[i])
            return (true);
        if (string1[i] < string2[i])
            return (false);
    }
    return (false);
}

void display_array(char **array, int size, list_p *list)
{
    char **tmp;

    tmp = create_tmp_array(size, array);
    sort(&tmp, size);
    swap_array_and_list(array, tmp, list, size);
    check_under(array, list, size);
    free_tabs(array, size);
    free_tabs(tmp, size);
    print_list(list);
}

char *my_str_to_uppercase(char *string)
{
    char *tmp;
    int cpt;

    cpt = 0;
    if ((tmp = malloc(sizeof(char) * strlen(string) + 1)) == NULL)
        return (NULL);
    for (; string[cpt] != '\0'; cpt++) {
        if (string[cpt] >= 'a' && string[cpt] <= 'z')
            tmp[cpt] = string[cpt] - 32;
        else
            tmp[cpt] = string[cpt];
    }
    tmp[cpt] = '\0';
    return (tmp);
}

char *delete_under(char *string)
{
    int i;

    for (i = 0; string[i] != '\0' && string[i] == '_';) {
        if (string[i + 1] == '_') {
            return (my_str_to_uppercase(string + i + 2));
        }
        if (string[i] == '_') {
            return (my_str_to_uppercase(string + i + 1));
        }
        i++;
    }
    return (my_str_to_uppercase(string + i));
}

char **list_to_array(list_p *list)
{
    char **array;
    int list_size = get_size_list(list);
    t_list *symbol;
    int compteur;
    int t;

    array = malloc(sizeof(*array) * list_size);
    symbol = list->head;
    t = 0;
    for (compteur = 0; symbol != NULL; compteur++) {
        if (symbol->name_symbol != NULL) {
            array[t] = strdup(symbol->name_symbol);
            t++;
        }
        symbol = symbol->next;
    }
    display_array(array, t, list);
    free(list);
    return (array);
}