/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

#include <exception>

#include "plazza.hpp"
#include "Reception.hpp"

int main(const int argc, const char **argv)
{
    try
    {
        Reception desk(argc, argv);

        desk.startPlazza();
    }
    catch (std::invalid_argument const &except)
    {
        std::cerr << except.what() << " '-h' or '--help' for USAGE." << std::endl;
        return ERROR;
    }
    return END;
}