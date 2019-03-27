/*
** EPITECH PROJECT, 2019
** OpenGl.hpp
** File description:
** OpenGl
*/

#include "SFML.hpp"

SFML::SFML()
{
}

SFML::~SFML()
{
}

void SFML::gfxLoop(IGfx::ACTION &COMMANDE)
{
    while (window.isOpen()) {
        getEvents(COMMANDE);
    }
}

void SFML::getEvents(IGfx::ACTION &COMMANDE)
{
    sf::Event event;
    COMMANDE = OTHER;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Num1) {
                COMMANDE = PREV_GFX;
                window.close();
            }
            if (event.key.code == sf::Keyboard::Key::Num2) {
                COMMANDE = NEXT_GFX;
                window.close();
            }
        }
    }
}
void SFML::createWindow()
{
}