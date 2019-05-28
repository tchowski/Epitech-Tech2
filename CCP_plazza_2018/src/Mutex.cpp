/*
** EPITECH PROJECT, 2019
** Mutex.cpp
** File description:
** Mutex
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
    this->_newMutex = PTHREAD_MUTEX_INITIALIZER;
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&this->_newMutex);
}

void Mutex::lock_mutex()
{
    pthread_mutex_lock(&this->_newMutex);
}

void Mutex::unlock_mutex()
{
    pthread_mutex_unlock(&this->_newMutex);
}

pthread_mutex_t &Mutex::getMutex()
{
    return _newMutex;
}