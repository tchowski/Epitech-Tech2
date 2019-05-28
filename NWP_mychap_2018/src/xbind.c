/*
** EPITECH PROJECT, 2019
** xbind.c
** File description:
** xbind
*/

#include "mychap.h"

void xbind(int fd_socket, sockaddr_in server)
{
    int check;

    check = bind(fd_socket, (struct sockaddr *)&server, sizeof(server));
    if (check == -1)
        my_perror("Bind");
}