/*
** EPITECH PROJECT, 2019
** APizza.hpp
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_


#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class APizza {
public:
    enum PizzaType {
        Undefined,
        Regina,
        Margarita,
        Americana,
        Fantasia
    };
    enum PizzaSize {
        S,
        M,
        L,
        XL,
        XXL
    };

    APizza(PizzaType type, PizzaSize size);
    ~APizza();
    virtual void setIngredients() = 0;
    virtual void setCookingTime() = 0;
    int getCookingTime() const;
    PizzaType getType() const;
    PizzaSize getSize() const;
    std::vector<std::string> const &getIngredients() const;

protected:
    int _cooktime;
    PizzaType _type;
    PizzaSize _size;
    std::vector<std::string> _ingredients;

private:
};

#endif /* !APIZZA_HPP_ */
