/*
** EPITECH PROJECT, 2019
** init_struct.c
** File description:
** init_struct
*/

#include "ftp.h"

void init_sockaddr_server(sockaddr_in *server, socket_t *socket_s)
{
    server->sin_family = AF_INET;
    server->sin_addr.s_addr = htonl(INADDR_ANY);
    server->sin_port = htons(socket_s->PORT);
}

void init_socket_struct(socket_t *socket_s, char const **argv)
{
    socket_s->PORT = atoi(argv[1]);
    socket_s->path = argv[2];
}

void init_user_connection(user_connection_t *user_connection)
{
    user_connection->username = strdup("Anonymous");
    user_connection->password = strdup("");
}

uint16_t init_pasv(data_t *data, sockaddr_in *their_addr, socklen_t *len)
{
    uint16_t port;

    *len = sizeof(*their_addr);
    data->data_fd = socket(AF_INET, SOCK_STREAM, 0);
    data->adress_socket_data.sin_family = AF_INET;
    data->adress_socket_data.sin_port = 0;
    data->adress_socket_data.sin_addr.s_addr = INADDR_ANY;
    bind(data->data_fd, (const struct sockaddr *)&data->adress_socket_data,
        sizeof(data->adress_socket_data));
    listen(data->data_fd, 1);
    getsockname(data->data_fd, (struct sockaddr *)&data->adress_socket_data,
        (socklen_t *)&len);
    port = ntohs(data->adress_socket_data.sin_port);
    return (port);
}

void init_port(data_t *data, char *address, char *port)
{
    int addrlen;

    data->data_fd = socket(AF_INET, SOCK_STREAM, 0);
    data->adress_socket_data.sin_family = AF_INET;
    data->adress_socket_data.sin_addr.s_addr = inet_addr(address);
    data->adress_socket_data.sin_port = htons(atoi(port));
    addrlen = sizeof(data->adress_socket_data);
    connect(data->data_fd, (const struct sockaddr *)&data->adress_socket_data,
        addrlen);
}