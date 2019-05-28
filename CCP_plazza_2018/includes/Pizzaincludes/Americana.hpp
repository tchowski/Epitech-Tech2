/*
** EPITECH PROJECT, 2019
** Americaine.hpp
** File description:
** Americaine
*/

#ifndef AMERICAINE_HPP_
#define AMERICAINE_HPP_

#include "APizza.hpp"

class Americana : public APizza {
public:
    Americana();
    Americana(APizza::PizzaSize size);
    ~Americana();
    virtual void setIngredients();
    virtual void setCookingTime() { this->_cooktime = 2; }
};

#endif /* !AMERICAINE_HPP_ */
