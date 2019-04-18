/*
** EPITECH PROJECT, 2019
** command.c
** File description:
** command
*/

#include "ftp.h"

static int basics_commands(int client_fd, const char *buffer)
{
    if (strncmp(buffer, "QUIT", 4) == 0) {
        message(client_fd, msg_221);
        return (1);
    } else if (strncmp(buffer, "HELP", 4) == 0) {
        message(client_fd, msg_214);
        return (0);
    }
    if (strncmp(buffer, "NOOP", 4) == 0) {
        message(client_fd, msg_200);
        return (0);
    }
    return (-1);
}

static int d_c(int client_fd, const char *buffer, socket_t *socket_s)
{
    char **tab = str_to_array((char *)buffer);

    if (strcmp(tab[0], "CWD") == 0) {
        if (tab[1] && dir_cwd(socket_s, tab[1]))
            message(client_fd, msg_250);
        else
            message(client_fd, "550 No such file or directory\r\n");
        return (0);
    }
    if (strcmp(tab[0], "PWD") == 0) {
        char *tmp = concat_pwd(socket_s->path);
        message(client_fd, tmp);
        free(tmp);
        return (0);
    }
    return (-1);
}

static int d_c2(int client_fd, const char *buffer, socket_t *socket_s)
{
    char **tab = str_to_array((char *)buffer);

    if (strcmp(tab[0], "CDUP") == 0) {
        parent_cdup((char *)socket_s->path);
        message(client_fd, msg_200);
        return (0);
    }
    if (strncmp(tab[0], "DELE", 4) == 0) {
        if (delete_dele(socket_s->path, tab[1]))
            message(client_fd, msg_250);
        else
            message(client_fd, "550 Impossible to remove the file\r\n");
        return (0);
    }
    return (-1);
}

int main_command_check(int client_fd, const char *buffer, socket_t *socket_s)
{
    int quit;

    if ((quit = basics_commands(client_fd, buffer)) == 0)
        return (0);
    if (quit == 1)
        return (-1);
    if (d_c(client_fd, buffer, socket_s) == 0)
        return (0);
    if (d_c2(client_fd, buffer, socket_s) == 0)
        return (0);
    if (data_command(client_fd, buffer) == 0)
        return (0);
    message(client_fd, msg_500);
    return (0);
}