/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Utils
*/

#include "Core.hpp"

unsigned int Core::PreviousLib(std::vector<std::string> &lib)
{
    unsigned int index = 0;

    while (index < lib.size()) {
        if (lib.at(index) == _currentLib) {
            if (index == 0)
                return (lib.size() - 1);
            return (index - 1);
        }
        index++;
    }
    return 0;
}

unsigned int Core::NextLib(std::vector<std::string> &lib)
{
    unsigned int index = 0;

    while (index < lib.size()) {
        if (lib.at(index) == _currentLib) {
            if (index == lib.size() - 1)
                return (0);
            return (index + 1);
        }
        index++;
    }
    return 0;
}

void Core::AddCompletePath(std::string &selectedLib)
{
    selectedLib = "./lib/" + selectedLib;
}

void Core::PrintVectors(std::vector<std::string> &Folder)
{
    for (unsigned int i = 0; i < Folder.size(); i++)
        std::cout << Folder[i] << std::endl;
}

void Core::GetLibraryPath()
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("./games")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] != '.' && strstr(ent->d_name, ".so"))
                Games.push_back(ent->d_name);
        }
    } else {
        perror("./games");
        exit(84);
    }
    if ((dir = opendir("./lib")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] != '.' && strstr(ent->d_name, ".so"))
                Libs.push_back(ent->d_name);
        }
    } else {
        perror("./lib");
        exit(84);
    }
    return;
}