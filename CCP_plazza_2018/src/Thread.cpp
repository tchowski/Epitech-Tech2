/*
** EPITECH PROJECT, 2019
** Plazza project
** File description:
** Thread.cpp
*/

#include "Thread.hpp"
#include <cstdlib>
#include <stdio.h>

Thread::Thread(void *(*start_routine)(void *), void *arg)
    : _status(Status::started)
    , _func(start_routine)
    , _arg(arg)
{
    printf("Getting Thread class\n");
}

void Thread::Start()
{
    if (pthread_create(&_thread, 0, _func, _arg) < 0)
        std::exit(84);
    _status = Status::running;
}

void Thread::Wait()
{
    pthread_join(_thread, NULL);
    _status = Status::dead;
}

Thread::Status Thread::getStatus()
{
    return _status;
}