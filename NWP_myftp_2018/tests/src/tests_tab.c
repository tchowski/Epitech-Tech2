/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** tab fts tests
*/

#include "ftp.h"
#include <criterion/criterion.h>
#include <stdio.h>
#include <unistd.h>

int tablen(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        i++;
    }
    return (i);
}

Test(tablen, _tab_size_2)
{
    char *tab[] = { "Undefined", "behaviour", NULL };

    cr_assert_eq(tablen(tab), 2);
}

Test(tablen, _tab_null)
{
    char *tab[] = { NULL };

    cr_assert_eq(tablen(tab), 0);
}

Test(str_to_array, split_with_space)
{
    char *s = strdup("split with space");
    char **t = str_to_array(s);

    cr_assert_str_eq(t[0], "split");
    cr_assert_str_eq(t[1], "with");
    cr_assert_str_eq(t[2], "space");
    cr_assert_null(t[3]);
}

Test(str_to_array, _path)
{
    char *s = strdup("/home/../home/tchowski");
    char **t = str_to_array(s);

    cr_assert_str_eq(t[0], "/home/../home/tchowski");
    cr_assert_null(t[1]);
}

Test(str_to_array, _null)
{
    char *s = strdup("\0");
    char **t = str_to_array(s);

    cr_assert_null(t[0]);
    cr_assert_not_null(t);
}