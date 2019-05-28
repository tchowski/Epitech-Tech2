/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "mychap.h"
#include <getopt.h>

static void switc_case_args(char c)
{
    switch (c) {
    case 0:
        break;
    case 't':
        break;
    case 'p':
        break;
    case 'P':
        break;
    case '?':
        print_usage_exit();
        break;
    default:
        printf("?? getopt returned character code 0%o ??\n", c);
        print_usage_exit();
    }
}

static void check_args_long(int argc, char **argv)
{
    int c;

    while ("J'aime les fesses de Patricia") {
        int option_index = 0;
        static struct option long_options[] = {
            { "target", required_argument, 0, 0 },
            { "port", required_argument, 0, 0 },
            { "password", required_argument, 0, 0 },
            { 0, 0, 0, 0 }
        };
        c = getopt_long(argc, argv, "t:p:P:", long_options, &option_index);
        if (c == -1)
            break;
        switc_case_args(c);
    }
    if (optind < argc)
        print_usage_exit();
}

int main(int argc, char **argv)
{
    if (argc != 7 || (argv[1] && strcmp(argv[1], "--help") == 0))
        return (print_usage());
    check_args_long(argc, argv);
    if (!check_port(argv))
        return (print_usage());
    if (check_dns(argv))
        hostname_to_ip(&argv[2]);
    socket_init(argv);
    return (0);
}