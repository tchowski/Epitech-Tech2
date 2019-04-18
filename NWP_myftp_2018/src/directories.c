/*
** EPITECH PROJECT, 2019
** utils2.c
** File description:
** utils2
*/

#include "ftp.h"
#include <sys/types.h>
#include <sys/wait.h>

bool dir_cwd(socket_t *socket_client, const char *new_path)
{
    DIR *dir;
    char buffer[254];

    strcpy(buffer, socket_client->path);
    if (strcmp(new_path, "..") == 0) {
        parent_cdup_adress((char **)&socket_client->path);
        return (true);
    }
    if (*new_path != '/') {
        strcat(buffer, "/");
        strcat(buffer, new_path);
        if ((dir = opendir(buffer)) != NULL) {
            memcpy((char *)socket_client->path, buffer, strlen(buffer) + 1);
            return (true);
        }
    }
    if ((dir = opendir(new_path)) != NULL) {
        socket_client->path = strdup(new_path);
        return (true);
    }
    return (false);
}

char *concat_pwd(const char *str)
{
    char *tmp;

    tmp = strdup("257 \"");
    tmp = realloc(tmp, (strlen(str) + strlen(tmp)) + 1);
    strcat(tmp, str);
    tmp = realloc(tmp, (strlen("\" created.\r\n") + strlen(tmp)) + 1);
    strcat(tmp, "\" created.\r\n");
    return (tmp);
}

bool delete_dele(const char *path, const char *file_name)
{
    int status;
    char *full_path;

    if (file_name[0] != '/')
        full_path = concat_path((char *)path, "/", file_name);
    else
        full_path = strdup(file_name);
    status = remove(full_path);
    if (status == 0)
        return (true);
    return (false);
}

bool list_list(int client_fd, const char *path)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (!d)
        return (false);
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name) {
            char *tmp = strdup(dir->d_name);
            tmp = realloc(tmp, (strlen(tmp) + 3));
            strcat(tmp, "\r\n");
            message(client_fd, tmp);
            free(tmp);
        }
    }
    if (dir == NULL)
        closedir(d);
    return (true);
}

void parent_cdup(char *path)
{
    char *token;

    path = revstr(path);
    token = strtok(path, "/");
    token = strtok(NULL, "");
    revstr(token);
    strcpy(path, token);
}