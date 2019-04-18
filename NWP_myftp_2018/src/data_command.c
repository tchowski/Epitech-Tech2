/*
** EPITECH PROJECT, 2019
** data.c
** File description:
** data
*/

#include "ftp.h"

int data_command3(int client_fd, const char *buffer)
{
    char **tab = str_to_array((char *)buffer);

    if (strncmp(tab[0], "PORT", 4) == 0) {
        if (!isPort)
            isPort = true;
        port(&data, client_fd, tab[1]);
        return (0);
    }
    if (strncmp(tab[0], "PASV", 4) == 0) {
        if (!isPort)
            isPort = true;
        pasv(&data, client_fd);
        return (0);
    }
    return (-1);
}

int data_command2(int client_fd, const char *buffer)
{
    char **tab = str_to_array((char *)buffer);

    if (strncmp(tab[0], "RETR", 4) == 0) {
        if (!isPort) {
            message(client_fd, msg_425);
            return (0);
        }
        message(client_fd, msg_150);
        message(client_fd, msg_226);
        return (0);
    } else if (strncmp(tab[0], "STOR", 4) == 0) {
        if (!isPort) {
            message(client_fd, msg_425);
            return (0);
        }
        message(client_fd, msg_150);
        message(client_fd, msg_226);
        return (0);
    }
    return (data_command3(client_fd, buffer) == 0 ? 0 : -1);
}

int data_command(int client_fd, const char *buffer)
{
    char **tab = str_to_array((char *)buffer);

    if (strncmp(tab[0], "LIST", 4) == 0) {
        if (!isPort) {
            message(client_fd, msg_425);
            return (0);
        }
        message(client_fd, msg_150);
        list(client_fd);
        return (0);
    }
    return (data_command2(client_fd, buffer) == 0 ? 0 : -1);
}