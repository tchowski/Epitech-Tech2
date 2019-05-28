/*
** EPITECH PROJECT, 2019
** Kitchen.hpp
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "APizza.hpp"
#include "ConditionVariableMutex.hpp"
#include "Message_q.hpp"
#include "Mutex.hpp"
#include "Reception.hpp"
#include "Thread.hpp"
#include "ThreadPool.hpp"
#include "Utils.hpp"
#include <string>
#include <unistd.h>
#include <vector>

class Kitchen {
public:
    Kitchen(std::string command, float multiplier, int nombreCuisinier, int _recepiesResetTime);
    ~Kitchen();
    void startCooking();
    // std::string getCommand() const;
    void *cookPizza();
    void *ingredient();
    void operator()() const
    {
        std::cout << "this=" << this << std::endl;
    }
    void startThread();
    int getNombreThreads() const;
    void StingToVector();
    std::vector<std::string> Split(const std::string &str, int splitLength);
    std::vector<std::string> StingToVector(std::string _command);
    APizza *MakePizza(APizza::PizzaType &pizzaType, APizza::PizzaSize &pizzaSize);
    Mutex *_mutex;
    ConditionVariableMutex *_condition;
    void decIngredient(APizza &pizza);
    void setIngredients();

protected:
private:
    pid_t pid;
    Utils *utils;
    Message_Q *_message_q;
    ThreadPool *_cook;
    ThreadPool *_ingredient;
    std::string _id_message = "/command";
    void kitchenNumbers();
    std::vector<std::string> _command;
    float _multiplier;
    int _nombreCuisinier;
    int _recepiesResetTime;
    std::map<std::string, int> _ingredients;
};

#endif /* !KITCHEN_HPP_ */
