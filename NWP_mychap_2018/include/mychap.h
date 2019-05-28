/*
** EPITECH PROJECT, 2019
** mychap.h
** File description:
** mychap
*/

#ifndef MYCHAP_H_
#define MYCHAP_H_

/* Includes */
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Defines */
#define msg_ko "KO"
#define PCKT_LEN 4090
#define client_hello "client hello"
#define NONCE_LENGTH 10

/* typedefs */
typedef struct sockaddr_in sockaddr_in;

/* Structure */
typedef struct socket_s {
    int port;
    char *target;
    char *password;
} socket_t;

/* globale */
unsigned char msg_server[255];
socket_t socket_s;
char package[PCKT_LEN];

/* Utils */
int print_usage(void);
bool check_port(char **argv);
void my_perror(const char *str);
bool check_dns(char **argv);
void print_usage_exit(void);
void run(int, sockaddr_in server, struct iphdr *ip, struct udphdr *udp);
char *sha256(const char *str);

/* Inits */
void init_sockaddr_server(sockaddr_in *server, socket_t *socket_s);
void init_socket_header_ip(struct iphdr *ip, char *tmp);
void init_socket_header_udp(struct udphdr *udp, char *tmp);
void init_socket_struct(socket_t *socket_s, char **argv);
void socket_init(char **argv);
unsigned short csum(unsigned short *buf, int nwords);

/* Sockets*/
void xsetsockopt(int *fd_socket);

/* Hostname_to_ip */
void hostname_to_ip(char **hostname);

/* Bind */
void xbind(int fd_socket, struct sockaddr_in server);

/* Print */
void print_udp_packet(unsigned char *Buffer, int size_packet);

/* Receivfrom */
int xreceivfrom(int, unsigned char **package_server, sockaddr_in si_other);

/* Sendfrom */
void xsendto(int fd_socket, u_int16_t size, sockaddr_in server);

#endif /* !MYCHAP_H_ */