/*
** EPITECH PROJECT, 2019
** Regina.hpp
** File description:
** Regina
*/

#ifndef REGINA_HPP_
#define REGINA_HPP_

#include "APizza.hpp"

class Regina : public APizza {

public:
    Regina();
    Regina(APizza::PizzaSize size);
    ~Regina();
    virtual void setIngredients();
    virtual void setCookingTime() { this->_cooktime = 2; }
};

#endif /* !REGINA_HPP_ */
