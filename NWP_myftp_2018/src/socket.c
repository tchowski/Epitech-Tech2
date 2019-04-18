/*
** EPITECH PROJECT, 2019
** socket.c
** File description:
** socket
*/

#include "ftp.h"
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int command_ftp(int client_fd, socket_t *socket_s)
{
    char buffer[256];
    int numread;
    user_connection_t user_connection;

    connection_check(client_fd);
    init_user_connection(&user_connection);
    fprintf(stderr, "Connexion Serveur - Client: ON!\n");
    isPort = false;
    while (1) {
        if ((numread = read(client_fd, buffer, sizeof(buffer) - 1)) == -1)
            my_perror("read");
        buffer[numread - 2] = '\0';
        if (main_command_check(client_fd,
                (const char *)&buffer, socket_s)
            == -1)
            break;
    }
    return (0);
}

void run_clients(int client_fd, int server_fd, socket_t *socket_s)
{
    pid_t pid;
    (void)server_fd;

    pid = check_pid();
    if (pid == 0) {
        command_ftp(client_fd, socket_s);
        fprintf(stderr, "Close Client\n");
        close(client_fd);
        exit(0);
    } else
        close(client_fd);
}

void run_server(int server_fd, sockaddr_in *server, socket_t *socket_s)
{
    int client_fd;
    sockaddr_in their_addr;
    int addrlen = sizeof(sockaddr_in);
    bool isRunning = true;
    (void)server;

    while (isRunning) {
        if ((client_fd = accept(server_fd,
                 (struct sockaddr *)&their_addr, (socklen_t *)&addrlen))
            < 0)
            my_perror("accept");
        printf("Connection depuis %s sur le port %d\n",
            inet_ntoa(their_addr.sin_addr),
            htons(their_addr.sin_port));
        message(client_fd, msg_220);
        run_clients(client_fd, server_fd, socket_s);
    }
}

void init_server(char const **argv)
{
    sockaddr_in server;
    socket_t socket_s;
    int server_fd;
    int opt = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        my_perror("Socket failed");
    init_socket_struct(&socket_s, argv);
    init_sockaddr_server(&server, &socket_s);
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt)))
        my_perror("setsockopt");
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) == -1)
        my_perror("Bind failed");
    if (listen(server_fd, 10) == -1)
        my_perror("Listen failed");
    run_server(server_fd, &server, &socket_s);
}