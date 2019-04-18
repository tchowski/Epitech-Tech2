/*
** EPITECH PROJECT, 2019
** data_command.c
** File description:
** data_command
*/

#include "ftp.h"

void list(int client_socket)
{
    int old_fd;
    pid_t pid;

    old_fd = dup(1);
    dup2(data.data_client_fd, 1);
    pid = fork();
    if (pid == 0)
        execl("/bin/ls", "ls", "-l", NULL);
    else
        waitpid(pid, 0, WSTOPPED);
    dup2(old_fd, 1);
    close(data.data_client_fd);
    message(client_socket, msg_226);
}

void port(data_t *data, int client_fd, char *tab)
{
    char **i = str_to_comma(tab);
    char *address = malloc(sizeof(char) * 50);
    char *port_data = malloc(sizeof(char) * 50);

    sprintf(address, "%s.%s.%s.%s", i[0], i[1], i[2], i[3]);
    sprintf(port_data, "%s%s", i[4], i[5]);
    fprintf(stderr, "Address: %s\n Port: %s\n", address, port_data);
    init_port(data, address, port_data);
    message(client_fd, msg_200);
    free(address);
    free(port_data);
}

void pasv(data_t *data, int client_fd)
{
    int port;
    sockaddr_in their_addr;
    socklen_t len;
    len = sizeof(their_addr);
    char buffer[254];

    port = init_pasv(data, &their_addr, &len);
    fprintf(stderr, "Port: %d\n", port);
    sprintf(buffer, "227 Entering Passive Mode (127,0,0,1,%d,%d)\r\n",
        port / 256, port % 256);
    message(client_fd, buffer);
    data->data_client_fd = accept(data->data_fd,
        (struct sockaddr *)&their_addr, &len);
}