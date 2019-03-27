/*
** EPITECH PROJECT, 2019
** SDL.hpp
** File description:
** SDL
*/

#ifndef OPENGL_HPP_
    #define OPENGL_HPP_

#include "../ILibGraphics.hpp"
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <algorithm>
#include <dlfcn.h>
#include <iostream>
#include <stdio.h>

class SDL : public IGfx{
	public:
		SDL();
		~SDL();
        virtual void createWindow();
        virtual void gfxLoop(IGfx::ACTION &COMMANDE);
		virtual void getEvents(IGfx::ACTION &COMMANDE);

	protected:
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
        bool quit = false;
		void destroyQuit();

};
	void keyPressed(unsigned char key, int x, int y);
	int OpenGlWindow = 0;
	int id;
	#define SCREEN_WIDTH 800
	#define SCREEN_HEIGHT 600

extern "C" IGfx* create() {
    return new SDL;
}
extern "C" void destroy(IGfx* p) {
 delete p;
}
#endif /* !OPENGL_HPP_ */
