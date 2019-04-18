/*
** EPITECH PROJECT, 2019
** usage.c
** File description:
** usage
*/

#include "ftp.h"

int print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
    return (84);
}

void my_perror(char *str)
{
    perror(str);
    exit(84);
}

void message(int client_fd, const char *str)
{
    write(client_fd, str, strlen(str));
}

bool check_connection(user_connection_t *user_connection)
{
    printf("Check connection: \n");
    printf("Password: %s", user_connection->password);
    printf(".\n");
    printf("Username: %s", user_connection->username);
    printf(".\n");
    if (strcmp(user_connection->username, "Anonymous") == 0)
        printf("USER: OK\n");
    if (strcmp(user_connection->password, "a") == 0)
        printf("PASS: OK\n");
    if (strcmp(user_connection->username, "Anonymous") == 0
        && strcmp(user_connection->password, "a") == 0) {
        printf("return true! \n");
        return (true);
    }
    printf("return false! \n");
    return (false);
}
