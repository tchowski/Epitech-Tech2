/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Reception Class Unit Tests
*/

#include <criterion/criterion.h>
#include <iostream>

#include "Reception.hpp"

Test(Reception, ctorDtor)
{
    const int argc = 4;
    const char *argv[] = {"./plazza", "1", "1", "1", NULL};
    const Reception desk(argc, argv);
    std::vector<std::string> vstr = desk.getCommand();

    cr_assert_eq(vstr.size(), 0);
    cr_assert_none_throw(new Reception(argc, argv));
    cr_assert_eq(desk.getMulti(), 1);
    cr_assert_eq(desk.getNbCook(), 1);
    cr_assert_eq(desk.getResetTime(), 1);
}

Test(Reception, invalidNbArgument)
{
    const int argc = 3;
    const char *argv[] = {"./plazza", "1", "1", NULL};

    cr_assert_any_throw(new Reception(argc, argv));
}

Test(Reception, wrongMultiplier)
{
    const int argc = 4;
    const char *argv[] = {"./plazza", "-1", "1", "1", NULL};

    cr_assert_any_throw(new Reception(argc, argv));
}

Test(Reception, wrongNbCook)
{
    const int argc = 4;
    const char *argv[] = {"./plazza", "1", "-1", "1", NULL};

    cr_assert_any_throw(new Reception(argc, argv));
}

Test(Reception, wrongResetTime)
{
    const int argc = 4;
    const char *argv[] = {"./plazza", "1", "1", "-1", NULL};

    cr_assert_any_throw(new Reception(argc, argv));
}

Test(Reception, help_flag1)
{
    const int argc = 2;
    const char *argv[] = {"./plazza", "--help", NULL};

    cr_assert_any_throw(new Reception(argc, argv));
}

Test(Reception, help_flag2)
{
    const int argc = 2;
    const char *argv[] = {"./plazza", "-h", NULL};

    cr_assert_any_throw(new Reception(argc, argv));
}