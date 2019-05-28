/*
** EPITECH PROJECT, 2019
** Plazza project
** File description:
** Thread.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_THREAD_HPP_
#define BOOTSTRAP_PLAZZA_THREAD_HPP_

#include <pthread.h>

class Thread {
public:
    Thread(void *(*start_routine)(void *), void *arg);
    ~Thread() = default;
    void Start();
    void Wait();
    enum class Status {
        started,
        running,
        dead
    };
    Thread::Status getStatus();

private:
    Status _status;
    pthread_t _thread;
    void *(*_func)(void *);
    void *_arg;
};

#endif //BOOTSTRAP_PLAZZA_THREAD_HPP_
