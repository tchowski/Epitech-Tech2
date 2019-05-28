/*
** EPITECH PROJECT, 2019
** Pizza.cpp
** File description:
** Pizza
*/

#include "Americana.hpp"
#include "Fantasia.hpp"
#include "APizza.hpp"
#include "Margarita.hpp"
#include "Regina.hpp"

/* Interface APizza */

APizza::APizza(PizzaType type, PizzaSize size)
    : _type(type)
    , _size(size)
{
}

APizza::~APizza()
{
}

APizza::PizzaType APizza::getType(void) const
{
    return (this->_type);
}

APizza::PizzaSize APizza::getSize(void) const
{
    return (this->_size);
}

int APizza::getCookingTime(void) const
{
    return (this->_cooktime);
}

std::vector<std::string> const &APizza::getIngredients() const
{
    return (_ingredients);
}

/* Pizza Margarita */

Margarita::Margarita(APizza::PizzaSize size = APizza::PizzaSize::S)
    : APizza(APizza::Margarita, size)
{
    setIngredients();
    setCookingTime();
}

void Margarita::setIngredients()
{
    _ingredients.push_back("doe");
    _ingredients.push_back("tomato");
    _ingredients.push_back("gruyere");
}

Margarita::~Margarita(void)
{
}

/* Pizza Americaine */

Americana::Americana(APizza::PizzaSize size = APizza::PizzaSize::S)
    : APizza(APizza::Americana, size)
{
    setIngredients();
    setCookingTime();
}

void Americana::setIngredients()
{
    _ingredients.push_back("doe");
    _ingredients.push_back("tomato");
    _ingredients.push_back("gruyere");
    _ingredients.push_back("steak");
}

Americana::~Americana(void)
{
}

/* Pizza Fantasia */

Fantasia::Fantasia(APizza::PizzaSize size = APizza::PizzaSize::S)
    : APizza(APizza::Fantasia, size)
{
    setIngredients();
    setCookingTime();
}

void Fantasia::setIngredients()
{
    _ingredients.push_back("doe");
    _ingredients.push_back("tomato");
    _ingredients.push_back("eggplant");
    _ingredients.push_back("goat cheese");
    _ingredients.push_back("chief love");
}

Fantasia::~Fantasia(void)
{
}

/* Pizza Regina */

Regina::Regina(APizza::PizzaSize size = APizza::PizzaSize::S)
    : APizza(APizza::Regina, size)
{
    setIngredients();
    setCookingTime();
}

void Regina::setIngredients()
{
    _ingredients.push_back("doe");
    _ingredients.push_back("tomato");
    _ingredients.push_back("gruyere");
    _ingredients.push_back("ham");
    _ingredients.push_back("mushrooms");
}

Regina::~Regina(void)
{
}

