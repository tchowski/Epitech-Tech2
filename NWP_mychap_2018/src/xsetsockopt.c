/*
** EPITECH PROJECT, 2019
** xsetsockopt.c
** File description:
** xsetsockopt
*/

#include "mychap.h"

void xsetsockopt(int *fd_socket)
{
    int one = 1;
    const int *val = &one;

    if (setsockopt(*fd_socket, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        my_perror("setsockopt() error");
        exit(84);
    }
}