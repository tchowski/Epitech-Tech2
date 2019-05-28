/*
** EPITECH PROJECT, 2019
** hostname_to_ip.c
** File description:
** hostname_to_ip
*/

#include "mychap.h"

void hostname_to_ip(char **hostname)
{
    char *ipbuffer;
    struct hostent *host_entry;

    host_entry = gethostbyname(*hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "No such hostname: \'%s\'\n", *hostname);
        exit(84);
    }
    ipbuffer = inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0]));
    memcpy(*hostname, ipbuffer, strlen(ipbuffer));
}