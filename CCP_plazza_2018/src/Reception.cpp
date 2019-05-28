/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Reception Implementation
*/

#include "Reception.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#define ever (; 42;)

const char *help[] = { "-h", "--help", NULL };

/* public */
Reception::Reception(const int nArg, const char **arg)
    : _order()
    , _multiplier(0)
    , _nCook(0)
    , _recepiesResetTime(0)
{
    std::string err;

    (void)(nArg);
    for (unsigned short it = 0; help[it] != NULL; it++) {
        if (nArg == 2 && strcmp(arg[1], help[it]) == 0) {
            err.append("USAGE: ");
            err.append(arg[0]);
            err.append(" [MULTIPLIER] [N_COOK] [RECEPIES_RESET_TIME]");
            throw std::invalid_argument(err);
        }
    }
    if (nArg != 4)
        throw std::invalid_argument("Invalid number of argument.");
    this->_multiplier = atof(arg[1]);
    this->_nCook = atoi(arg[2]);
    this->_recepiesResetTime = atoi(arg[3]);
    if (this->_multiplier <= 0)
        throw std::invalid_argument("Multiplier should be non-nul positive float.");
    if (this->_nCook <= 0)
        throw std::invalid_argument("Cook number should be non-nul positive int.");
    if (this->_recepiesResetTime <= 0)
        throw std::invalid_argument("Reset time should be non-nul positive int.");
}

Reception::~Reception()
{
}

std::vector<std::string> Reception::getCommand() const
{
    return this->_order;
}

int Reception::getMulti() const
{
    return this->_multiplier;
}

int Reception::getNbCook() const
{
    return this->_nCook;
}

int Reception::getResetTime() const
{
    return this->_recepiesResetTime;
}

void Reception::startPlazza()
{
    int status;
    bool first_time = true;

    while (42) {
        std::cout << "What will you take?" << std::endl;
        this->listenOrder();
        if (this->checkOrder() == false)
            continue;
        std::cout << "Your command has been send to the kitchens!" << std::endl;
        if (first_time) {
            _process = new Process();
            _message_q = new Message_Q(_id_message, getPizza().c_str());
            _message_q->send_message_queue();
            _message_q->close_message_queue();
            if (_process->getPid() == 0) {
                _message_q = new Message_Q(_id_message);
                _message_q->receive_message_queue();
                std::cout << "Getting child" << std::endl;
                Kitchen *kitchen = new Kitchen(_message_q->_buf, this->_multiplier, getNbCook(), _recepiesResetTime);
                _message_q->unlink(_id_message);
                _message_q->close_message_queue();
            }
            waitpid(_process->getPid(), &status, 0);
            std::cout << "Getting Parent" << std::endl;
        }
    }
}

std::string Reception::getPizza() const
{
    return s;
}

/* private */
void Reception::listenOrder()
{
    std::getline(std::cin, s);
    this->splitString(s, ' ');
}

void Reception::splitString(const std::string &str, char delim)
{
    auto first_it = str.begin();
    auto last_it = str.end();

    this->_order.clear();
    while (first_it != last_it) {
        auto it = std::find(first_it, last_it, delim);
        this->_order.emplace_back(first_it, it);
        if (it == last_it)
            break;
        it++;
        first_it = it;
    }
    this->_order.erase(std::remove_if(this->_order.begin(), this->_order.end(),
                           [](const std::string &s) { return s.empty(); }),
        this->_order.end());
}

bool Reception::checkOrder() const
{
    std::regex pizzaType("^(REGINA|MARGARITA|AMERICANA|FANTASIA)", std::regex::icase);
    std::regex pizzaSize("^(S|M|L|XL|XXL)");
    std::regex pizzaNumber("^x[[:digit:]]{1,2};?");

    if (this->_order.size() % 3 != 0) {
        std::cout << "Invalid ordering format" << std::endl;
        return false;
    }
    for (size_t it = 0; it < this->_order.size(); it++) {
        if (it % 3 == 0 && std::regex_match(this->_order.at(it), pizzaType) == false) {
            std::cout << "Invalid pizza name" << std::endl;
            return false;
        }
        if (it % 3 == 1 && std::regex_match(this->_order.at(it), pizzaSize) == false) {
            std::cout << "Invalid pizza size" << std::endl;
            return false;
        }
        if (it % 3 == 2 && std::regex_match(this->_order.at(it), pizzaNumber) == false) {
            std::cout << "Invalid pizza number" << std::endl;
            return false;
        }
        if (it < (this->_order.size() - 1) && it % 3 == 2 && this->_order[it].at(this->_order[it].size() - 1) != ';') {
            std::cout << "Wrong ordering format" << std::endl;
            return false;
        }
    }
    return true;
}

void Reception::prepareOrder()
{
    unsigned short multi = 0;

    for (size_t it = 0; it < this->_order.size(); it += 3) {
        for (multi = this->getOrderPizzaNumber(this->_order.at(it + 2)); multi > 0; multi--) {
            this->_pizzaQueue.emplace(this->_order.at(it));
            this->_sizeQueue.emplace(this->_order.at(it + 1));
        }
    }
}

unsigned short Reception::getOrderPizzaNumber(std::string pizzaNumber)
{
    unsigned short retval = 0;
    std::istringstream iss;

    pizzaNumber.erase(pizzaNumber.begin());
    iss.str(pizzaNumber);
    iss >> retval;
    return (retval);
}

void Reception::clearQueue(std::queue<std::string> &queue)
{
    while (not queue.empty()) {
        queue.pop();
    }
}
