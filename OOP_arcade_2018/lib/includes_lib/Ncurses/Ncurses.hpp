/*
** EPITECH PROJECT, 2019
** Ncurses.hpp
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

#include "../ILibGraphics.hpp"
#include <ncurses.h>

class Ncurses : public IGfx{
	public:
		Ncurses();
		~Ncurses();
        virtual void createWindow();
        virtual void gfxLoop(IGfx::ACTION &COMMANDE);
		virtual void getEvents(IGfx::ACTION &COMMANDE);


	protected:
	private:
    	WINDOW *menu_win;
    	int highlight = 1;
		int choice = 0;
    	int c;


};

extern "C" IGfx* create() {
    return new Ncurses;
}

extern "C" void destroy(IGfx* p) {
 delete p;
}
#endif /* !NCURSES_HPP_ */
