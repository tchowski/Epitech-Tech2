/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Reception Header | Get Pizza Commands
*/

#ifndef RECEPTION_H_
#define RECEPTION_H_

#include "Kitchen.hpp"
#include "Message_q.hpp"
#include "Process.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#include <queue>

class Reception {
public:
    Reception(const int, const char **);
    Reception() {}
    ~Reception();
    std::vector<std::string> getCommand() const;
    int getMulti() const;
    int getNbCook() const;
    int getResetTime() const;
    void startPlazza();
    Process *_process;
    std::string _id_message = "/command";
    std::string s;
    std::string getPizza() const;

private:
    std::vector<std::string> _order;
    pid_t pid;
    Utils *_utils;
    Message_Q *_message_q;
    std::queue<std::string> _pizzaQueue;
    std::queue<std::string> _sizeQueue;
    int _multiplier;
    int _nCook;
    int _recepiesResetTime;
    void listenOrder();
    void splitString(const std::string &, char);
    bool checkOrder() const;
    void prepareOrder();
    unsigned short getOrderPizzaNumber(std::string);
    void clearQueue(std::queue<std::string> &);
};

#endif /* !RECEPTION_H_ */
