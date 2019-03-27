/*
** EPITECH PROJECT, 2019
** Core
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include "Arcade.hpp"
#include <algorithm>
#include "../lib/includes_lib/ILibGraphics.hpp"

class Core : public Arcade {
	public:
		Core(const std::string libPath);
		~Core() = default;
		virtual void GameLoop();
		virtual void GetLibraryPath();

        std::vector<std::string> Games;
        std::vector<std::string> Libs;
        unsigned int PreviousLib(std::vector<std::string> &lib);
        unsigned int NextLib(std::vector<std::string> &lib);
    protected:
	private:
        bool isOpen = true;
        void *_handler;
        void AddCompletePath(std::string &selectedLib);
        void Opendl(const std::string);
        void PrintVectors(std::vector<std::string> &Folder);
        IGfx *setSymdl();
        void destroyClass(IGfx *lib);
        void closeLib();
};

#endif /* !CORE_HPP_ */
