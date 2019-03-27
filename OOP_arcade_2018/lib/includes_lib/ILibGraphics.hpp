/*
** EPITECH PROJECT, 2019
** ILibGraphics
** File description:
** ILibGraphics
*/

#ifndef ILIBGRAPHICS_HPP_
    #define ILIBGRAPHICS_HPP_

#include <iostream>
#include <vector>

class IGfx {
	public:
        enum ACTION {
            MOVE_UP,
            MOVE_DOWN,
            MOVE_LEFT,
            MOVE_RIGHT,
            NEXT_GFX,
            PREV_GFX,
            NEXT_GAME,
            PREV_GAME,
            RESTART,
            MENU,
            EXIT,
            OTHER
        };
        IGfx::ACTION COMMANDE;

        virtual ~IGfx() = default;
        virtual void gfxLoop(IGfx::ACTION &COMMANDE) = 0;
        virtual void getEvents(IGfx::ACTION &COMMANDE) = 0;
        virtual void createWindow() = 0;
        // virtual void drawMap(std::unique_ptr<Map> map) = 0;
        // virtual int menu(std::vector<std::string> games) = 0;
        // virtual void clear() = 0;
        // virtual void setGame(std::shared_ptr<IGame> game) = 0;
        // virtual void drawWall(int posX, int posY) = 0;
        // virtual void drawPlayer(int posX, int posY) = 0;
        // virtual void drawPickup(int posX, int posY) = 0;
        // virtual void drawEnemy(int posX, int posY) = 0;
        // virtual void drawMovDoor(int posX, int posY) = 0;
        // virtual void drawUniqueDoor(int posX, int posY) = 0;

	protected:
	private:
};
typedef IGfx* create_t();
typedef void destroy_t(IGfx*);

#endif /* !ILIBGRAPHICS_HPP_ */
