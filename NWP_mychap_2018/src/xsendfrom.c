/*
** EPITECH PROJECT, 2019
** xsendfrom.c
** File description:
** xsendfrom
*/

#include "mychap.h"

void xsendto(int fd_socket, u_int16_t size, sockaddr_in server)
{
    int send_len;

    send_len = sendto(fd_socket, package, size, 0,
        (struct sockaddr *)&server, sizeof(server));
    if (send_len < 0)
        my_perror("Send");
}
