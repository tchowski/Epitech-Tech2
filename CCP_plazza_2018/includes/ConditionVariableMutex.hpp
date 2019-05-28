/*
** EPITECH PROJECT, 2019
** ConditionVariable.hpp
** File description:
** ConditionVariable
*/

#ifndef CONDITIONVARIABLE_HPP_
#define CONDITIONVARIABLE_HPP_

#include "plazza.hpp"

class ConditionVariableMutex {
public:

    ConditionVariableMutex();
    ~ConditionVariableMutex();
    void cond_wait(pthread_mutex_t &mutex);
    void cond_signal();
    void cond_broadcast();

protected:
private:
    pthread_cond_t _condition; /* Création de la condition */
};

#endif /* !CONDITIONVARIABLE_HPP_ */
