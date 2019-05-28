/*
** EPITECH PROJECT, 2019
** plazza.hpp
** File description:
** plazza
*/

#include "APizza.hpp"
#include "Utils.hpp"
#include "Mutex.hpp"
#include <iostream>
#include <mutex>
#include <stdio.h>
#include <string.h>
#include <thread>

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#define UNUSED(var)    (void)(var)

typedef enum
{
    END,
    ERROR = 84
} retval_t;

class Plazza {
public:
    Plazza();
    ~Plazza();

protected:
private:
};

#endif /* !PLAZZA_HPP_ */
