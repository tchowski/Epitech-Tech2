/*
** EPITECH PROJECT, 2019
** wait_pid.c
** File description:
** wait_pid
*/

#include "strace.h"

int fprint_wait_status(int status)
{
    if (WIFSTOPPED(status)) {
        int sig;
        sig = WSTOPSIG(status);
        if (sig == 11) {
            return (139);
        } else if (sig == 8) {
            return (136);
        }
    }
    if (WIFEXITED(status)) {
        return (WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
        return (WTERMSIG(status) + WCOREDUMP(status));
    }
    return (0);
}
