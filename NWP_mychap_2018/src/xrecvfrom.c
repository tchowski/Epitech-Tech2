/*
** EPITECH PROJECT, 2019
** xreceivfrom.c
** File description:
** xrecvfrom
*/

#include "mychap.h"

int xreceivfrom(int fd, unsigned char **package_server, sockaddr_in si_other)
{
    int recv_len;

    recv_len = recvfrom(fd, *package_server, 256, 0,
        (struct sockaddr *)&si_other,
        (socklen_t[1]){ sizeof(struct sockaddr_in) });
    if (recv_len == -1)
        my_perror("recvfrom()");
    return (recv_len);
}