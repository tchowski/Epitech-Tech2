/*
** EPITECH PROJECT, 2019
** SFML.hpp
** File description:
** SFML
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include "../ILibGraphics.hpp"
#include <SFML/Window.hpp>

class SFML : public IGfx{
	public:
		SFML();
		~SFML();
        virtual void createWindow();
        virtual void gfxLoop(IGfx::ACTION &COMMANDE);
		virtual void getEvents(IGfx::ACTION &COMMANDE);

	protected:
	private:

};
    sf::Window window(sf::VideoMode(800, 600), "Arcade");
extern "C" IGfx* create() {
    return new SFML;
}

extern "C" void destroy(IGfx* p) {
 delete p;
}

#endif /* !SFML_HPP_ */
