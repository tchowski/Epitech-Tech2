/*
** EPITECH PROJECT, 2019
** run.c
** File description:
** run
*/

#include "mychap.h"

void phase_1(int fd_socket, u_int16_t size, sockaddr_in server)
{
    xsendto(fd_socket, size, server);
}

void phase_2(int fd_socket)
{
    unsigned char *package_server = (unsigned char *)malloc(256);
    struct sockaddr_in si_other;
    int recv_len;

    si_other.sin_family = AF_INET;
    si_other.sin_addr.s_addr = htonl(INADDR_ANY);
    si_other.sin_port = htons(socket_s.port);
    while (1) {
        recv_len = xreceivfrom(fd_socket, &package_server, si_other);
        package[recv_len] = 0;
        print_udp_packet(package_server, recv_len);
        if (strlen((const char *)msg_server) == 10)
            break;
        memset(msg_server, 0, 255);
    }
    strcat((char *)msg_server, socket_s.password);
    memset(package, 0, PCKT_LEN);
}

void phase_3(int fd, sockaddr_in server, struct iphdr *ip, struct udphdr *udp)
{
    ip = (struct iphdr *)package;
    udp = (struct udphdr *)(package + sizeof(struct iphdr));
    char *mg = (char *)(package + sizeof(struct udphdr) + sizeof(struct iphdr));

    memcpy(mg, sha256((const char *)msg_server),
        strlen(sha256((const char *)msg_server)));
    init_socket_header_ip(ip, mg);
    init_socket_header_udp(udp, mg);
    ip->check = csum((unsigned short *)package,
        sizeof(struct iphdr) + sizeof(struct udphdr));
    xsendto(fd, ip->tot_len, server);
    memset(msg_server, 0, 255);
}

void phase_4(int fd_socket)
{
    unsigned char *package_server = (unsigned char *)malloc(256);
    struct sockaddr_in si_other;
    int recv_len;

    si_other.sin_family = AF_INET;
    si_other.sin_addr.s_addr = htonl(INADDR_ANY);
    si_other.sin_port = htons(socket_s.port);
    while (1) {
        recv_len = xreceivfrom(fd_socket, &package_server, si_other);
        package_server[recv_len] = 0;
        print_udp_packet(package_server, recv_len);
        if (strlen((const char *)msg_server) == 2)
            break;
        if (strlen((const char *)msg_server) > 1)
            break;
    }
    if (strncmp((char *)msg_server, "KO", 2) == 0)
        fprintf(stderr, "KO\n");
    else
        fprintf(stderr, "Secret: \'%s\'\n", msg_server);
}

void run(int fd, sockaddr_in server, struct iphdr *ip, struct udphdr *udp)
{
    phase_1(fd, ip->tot_len, server);
    phase_2(fd);
    phase_3(fd, server, ip, udp);
    phase_4(fd);
    close(fd);
}