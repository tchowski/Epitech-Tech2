/*
** EPITECH PROJECT, 2019
** ThreadPool.cpp
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int number, void *(*start_routine)(void *), void *arg)
{
    int i = 0;
    while (i < number) {
        _threadsPool.push_back(new Thread(start_routine, arg));
        i++;
    }
}

ThreadPool::~ThreadPool()
{
}
