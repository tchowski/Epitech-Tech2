/*
** EPITECH PROJECT, 2019
** Utils.hpp
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <unistd.h>
#include <vector>

class Utils {
public:
    void print_map(std::map<std::string, int> tab);
    pid_t check_pid(void);
    void print_vector(std::vector<std::string>const &path);

protected:
private:
};

#endif /* !UTILS_HPP_ */
