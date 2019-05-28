/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Utils
*/

#include "Utils.hpp"
#include <iostream>
#include <string>
#include <vector>

void Utils::print_map(std::map<std::string, int> tab)
{
    std::map<std::string, int>::iterator it = tab.begin();
    while (it != tab.end()) {
        std::cout << it->first << " :: " << it->second << std::endl;
        it++;
    }
}

pid_t Utils::check_pid(void)
{
    pid_t pid;
    if ((pid = fork()) == -1) {
        throw std::invalid_argument("Fork Failed.");
        exit(84);
    }
    return (pid);
}

void Utils::print_vector(std::vector<std::string> const &path)
{
    for (std::vector<std::string>::const_iterator i = path.begin(); i != path.end(); ++i)
        std::cout << *i << std::endl;
}

// void Utils::splitString(const std::string &str, char delim)
// {
//     auto first_it = str.begin();
//     auto last_it = str.end();

//     _order.clear();
//     while (first_it != last_it) {
//         auto it = std::find(first_it, last_it, delim);
//         _order.emplace_back(first_it, it);
//         if (it == last_it)
//             break;
//         it++;
//         first_it = it;
//     }
//     _order.erase(std::remove_if(_order.begin(), _order.end(),
//                      [](const std::string &s) { return s.empty(); }),
//         _order.end());
// }
