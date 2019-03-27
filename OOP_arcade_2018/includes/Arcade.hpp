/*
** EPITECH PROJECT, 2019
** Arcade.hpp
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_

#include <iostream>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <dirent.h>
#include "../lib/includes_lib/ILibGraphics.hpp"

class Arcade {
	public:
        std::string _currentLib;
		Arcade(const std::string libPath);
		~Arcade();
		virtual void GameLoop() = 0;
		virtual void GetLibraryPath() = 0;

	protected:
	private:
};
int help();

#endif /* !ARCADE_HPP_ */
