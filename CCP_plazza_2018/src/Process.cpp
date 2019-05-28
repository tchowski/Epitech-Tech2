/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Desc
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "Process.hpp"
#include <stdio.h>

Process::Process()
{
    _pid = fork();
}

Process::~Process()
{
//     if (_pid != 0)
//         waitpid(_pid, NULL, 0);
}

pid_t Process::getPid() const
{
    return _pid;
}