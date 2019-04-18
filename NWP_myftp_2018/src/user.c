/*
** EPITECH PROJECT, 2019
** user.c
** File description:
** user
*/

#include "ftp.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

void set_username(user_connection_t *user_connection, const char *username)
{
    user_connection->username = strdup(username);
}

void set_password(user_connection_t *user_connection, const char *password)
{
    user_connection->password = strdup(password);
}

char *filter_read(int socket_client)
{
    char *tmp = NULL;
    char *line = NULL;

    if ((line = malloc(sizeof(char) * 50)) == NULL)
        exit(0);
    memset(line, 0, 48);
    if ((tmp = malloc(sizeof(char) * 50)) == NULL)
        exit(0);
    while (line[strlen(line) - 1] != '\n' && line[strlen(line) - 2] != '\r') {
        memset(tmp, 0, 48);
        read(socket_client, tmp, 50);
        strcat(line, tmp);
    }
    return (line);
}

static void loopconnection(char **tab, int client_fd, int *count,
    user_connection_t *user_connection)
{
    if (strcmp(tab[0], "USER") == 0) {
        set_username(user_connection, tab[1]);
        message(client_fd, msg_331);
        if (*count == 1)
            *count = 1;
        else
            *count = *count + 1;
    } else if (strcmp(tab[0], "PASS") == 0) {
        set_password(user_connection, "a");
        *count = *count + 1;
    } else if (strcmp(tab[0], "QUIT") == 0) {
        message(client_fd, msg_221);
        close(client_fd);
        exit(0);
    } else
        message(client_fd, msg_530);
}

void connection_check(int client_fd)
{
    int count = 0;
    user_connection_t user_connection;
    char *line = NULL;
    char **tab = NULL;
    bool isConnected = false;

    while (!isConnected) {
        line = filter_read(client_fd);
        tab = str_to_array(line);
        loopconnection(tab, client_fd, &count, &user_connection);
        if (count == 2)
            isConnected = true;
    }
    if (check_connection(&user_connection) == true)
        message(client_fd, msg_230);
    else {
        message(client_fd, msg_530);
        connection_check(client_fd);
    }
}