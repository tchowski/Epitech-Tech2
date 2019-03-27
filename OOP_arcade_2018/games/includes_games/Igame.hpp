/*
** EPITECH PROJECT, 2019
** Igame
** File description:
** Igame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

#include <iostream>
#include <vector>
#include <memory>

class Igame {
	public:
		enum ENTITY {
            WALL,
            PLAYER,
            PICKUP,
            ENEMY,
            MOV_DOOR,
            UNIQUE_DOOR,
            OTHER
        };

        // virtual void updateMap() = 0;
        // virtual void play() = 0;
        // virtual void generateMap() = 0;
        // virtual void displayScore(int posX, int posY, int value) = 0;
        // virtual std::unique_ptr<Map> getMap() = 0;

	protected:
	private:
};

#endif /* !IGAME_HPP_ */
