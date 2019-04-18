/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** compare ft tests
*/

#include <criterion/criterion.h>
#include <stdbool.h>
#include <string.h>

#include "ftp.h"

bool compare(const char *s1, const char *s2);

Test(comapare, two_same_string)
{
    char *s1 = strdup("Tchowski");
    char *s2 = strdup("Tchowski");
    char *s3 = NULL;
    char *s4 = NULL;

    cr_assert_eq(compare(s1, s2), true);
    cr_assert_eq(compare(s3, s4), true);
}

Test(compare, one_string_shorter)
{
    char *s1 = strdup("Tchowski");
    char *s2 = strdup("Tchow");

    cr_assert_eq(compare(s1, s2), false);
    cr_assert_eq(compare(s2, s1), false);
}

Test(compare, one_string_null)
{
    char *s1 = strdup("Tchowski");
    char *s2 = NULL;

    cr_assert_eq(compare(s1, s2), false);
    cr_assert_eq(compare(s2, s1), false);
}