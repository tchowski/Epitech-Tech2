/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init
*/

#include "mychap.h"

unsigned short csum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

void init_socket_header_ip(struct iphdr *ip, char *tmp)
{
    u_int32_t dst_addr;
    u_int32_t src_addr;

    dst_addr = inet_addr(socket_s.target);
    src_addr = inet_addr("127.0.0.1");
    ip->ihl = 5;
    ip->version = 4;
    ip->tos = 16;
    ip->tot_len = sizeof(struct iphdr) + sizeof(struct udphdr) + strlen(tmp);
    ip->id = 0;
    ip->ttl = 64;
    ip->protocol = 17;
    ip->check = 0;
    ip->saddr = src_addr;
    ip->daddr = dst_addr;
}

void init_socket_header_udp(struct udphdr *udp, char *tmp)
{
    udp->source = htons(atoi("42"));
    udp->dest = htons(socket_s.port);
    udp->len = htons(sizeof(struct udphdr) + strlen(tmp));
}

void init_sockaddr_server(sockaddr_in *server, socket_t *socket_s)
{
    server->sin_family = AF_INET;
    server->sin_addr.s_addr = htonl(INADDR_ANY);
    server->sin_port = htons(socket_s->port);
}

void init_socket_struct(socket_t *socket_s, char **argv)
{
    socket_s->target = strdup(argv[2]);
    socket_s->port = atoi(argv[4]);
    socket_s->password = strdup(argv[6]);
}