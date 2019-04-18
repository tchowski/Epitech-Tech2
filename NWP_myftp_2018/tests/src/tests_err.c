/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** error handing tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>

#include "ftp.h"

bool check_input(int ac, char **av);

Test(check_input, no_error)
{
    int n_arg = 3;
    char *arg[] = { "./myftp", "4242", "/home/tchowski", NULL };
    bool err = check_input(n_arg, arg);

    cr_assert_eq(err, true);
}

Test(check_input, invalid_number_of_argument)
{
    int n_arg = 1;
    char *arg[] = { "./myftp", NULL };
    bool err = true;

    cr_redirect_stderr();
    err = check_input(n_arg, arg);
    cr_assert_eq(err, false);
    cr_assert_stderr_eq_str("USAGE: ./myftp [PORT] [PATH]\n");
}

Test(check_input, dash_h)
{
    int n_arg = 2;
    char *arg[] = { "./myftp", "-h", NULL };
    bool err = true;

    cr_redirect_stderr();
    err = check_input(n_arg, arg);
    cr_assert_eq(err, false);
    cr_assert_stderr_eq_str("USAGE: ./myftp [PORT] [PATH]\n");
}

Test(check_input, dash_dash_help)
{
    int n_arg = 2;
    char *arg[] = { "./myftp", "--help", NULL };
    bool err = true;

    cr_redirect_stderr();
    err = check_input(n_arg, arg);
    cr_assert_eq(err, false);
    cr_assert_stderr_eq_str("USAGE: ./myftp [PORT] [PATH]\n");
}

Test(check_input, invalid_dir)
{
    int n_arg = 3;
    char *arg[] = { "./myftp", "4242", "/null", NULL };
    bool err = true;

    cr_redirect_stderr();
    err = check_input(n_arg, arg);
    cr_assert_eq(err, false);
    cr_assert_stderr_eq_str("Error: directory doesn't exist.\n");
}
