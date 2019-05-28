/*
** EPITECH PROJECT, 2019
** Fantasia.hpp
** File description:
** Fantasia
*/

#ifndef FANTASIA_HPP_
#define FANTASIA_HPP_

#include "APizza.hpp"

class Fantasia : public APizza {
public:
    Fantasia();
    Fantasia(APizza::PizzaSize size);
    ~Fantasia();
    virtual void setIngredients();
    virtual void setCookingTime() { this->_cooktime = 4; }
};

#endif /* !FANTASIA_HPP_ */
