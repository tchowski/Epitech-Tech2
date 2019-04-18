/*
** EPITECH PROJECT, 2019
** utils2.c
** File description:
** utils2
*/

#include "ftp.h"

char *concat_path(char *source, const char *element, const char *origin)
{
    char *tmp = malloc(sizeof(char) + ((strlen(source) + strlen(origin)) + 1));
    char *sourcetmp = strdup(source);

    tmp = strcat(sourcetmp, element);
    tmp = strcat(tmp, origin);
    return (tmp);
}

char *revstr(char *str)
{
    char strc;
    int i;
    int j;

    i = 0;
    j = strlen(str) - 1;
    while (i < j) {
        strc = str[j];
        str[j] = str[i];
        str[i] = strc;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}

void parent_cdup_adress(char **path)
{
    char *token;

    revstr(*path);
    token = strtok(*path, "/");
    token = strtok(NULL, "");
    revstr(token);
    memcpy(*path, token, strlen(token) + 1);
}