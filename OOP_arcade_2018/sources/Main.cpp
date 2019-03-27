/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

// #include "Arcade.hpp"
#include "Core.hpp"

int main(int argc, char const *argv[])
{
    const char *libPath;

    if (argc < 2)
        return (help());
    else {
        if (argv[1]) {
            libPath = strdup(argv[1]);
            Core core(libPath);
            core.GameLoop();
        } else {
            return (help());
        }
    }
    return 0;
}