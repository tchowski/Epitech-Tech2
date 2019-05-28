/*
** EPITECH PROJECT, 2019
** socket.c
** File description:
** socket
*/

#include "mychap.h"

void socket_init(char **argv)
{
    sockaddr_in server;
    int fd_socket;
    memset(package, 0, PCKT_LEN);
    struct iphdr *ip = (struct iphdr *)package;
    struct udphdr *udp = (struct udphdr *)(package + sizeof(struct iphdr));
    char *mg = (char *)(package + sizeof(struct udphdr) + sizeof(struct iphdr));

    memcpy(mg, client_hello, strlen(client_hello));
    if ((fd_socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)) == -1)
        my_perror("Socket failed");
    xsetsockopt(&fd_socket);
    init_socket_struct(&socket_s, argv);
    init_sockaddr_server(&server, &socket_s);
    init_socket_header_ip(ip, mg);
    init_socket_header_udp(udp, mg);
    xbind(fd_socket, server);
    ip->check = csum((unsigned short *)package,
        sizeof(struct iphdr) + sizeof(struct udphdr));
    run(fd_socket, server, ip, udp);
}