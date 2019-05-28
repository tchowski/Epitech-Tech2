/*
** EPITECH PROJECT, 2019
** Margarita.hpp
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_

#include "APizza.hpp"

class Margarita : public APizza {
public:
    Margarita(APizza::PizzaSize size);
    ~Margarita();
    virtual void setIngredients();
    virtual void setCookingTime() { this->_cooktime = 1; }
};

#endif /* !MARGARITA_HPP_ */
