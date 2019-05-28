/*
** EPITECH PROJECT, 2019
** ConditionVariable
** File description:
** ConditionVariable
*/

#include "ConditionVariableMutex.hpp"

ConditionVariableMutex::ConditionVariableMutex()
{
    _condition = PTHREAD_COND_INITIALIZER;
}

ConditionVariableMutex::~ConditionVariableMutex()
{
    pthread_cond_destroy(&this->_condition);
}

void ConditionVariableMutex::cond_wait(pthread_mutex_t &mutex)
{
    pthread_cond_wait(&this->_condition, &mutex);
}

void ConditionVariableMutex::cond_signal()
{
    pthread_cond_signal(&this->_condition);
}

void ConditionVariableMutex::cond_broadcast()
{
    pthread_cond_broadcast(&this->_condition);
}