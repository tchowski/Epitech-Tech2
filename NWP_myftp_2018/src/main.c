/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "ftp.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
        return (print_usage());
    if (argv[1] && strcmp(argv[1], "--help") == 0)
        return (print_usage());
    if (!check_port(argv) || !check_path(argv))
        return (84);
    rootPath = strdup(argv[2]);
    init_server(argv);
    return (0);
}
