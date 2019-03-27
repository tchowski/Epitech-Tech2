/*
** EPITECH PROJECT, 2019
** OpenGl.hpp
** File description:
** OpenGl
*/

#include "Ncurses.hpp"

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

const char *choices[] = {
    "Jeux 1",
    "Jeux 2",
    "Quitter",
};
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses()
{
}

void Ncurses::gfxLoop(IGfx::ACTION &COMMANDE)
{
    COMMANDE = OTHER;

    noecho();
    cbreak();
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    refresh();
    print_menu(menu_win, highlight);
    getEvents(COMMANDE);
}

void Ncurses::getEvents(IGfx::ACTION &COMMANDE)
{
    while (1) {
        c = wgetch(menu_win);
        switch (c) {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10: /* Enter */
            choice = highlight;
            break;
        case 49: /* PREVIOUS_LIB */
            choice = highlight;
            COMMANDE = PREV_GFX;
            break;
        case 50: /* Next_LIB */
            choice = highlight;
            COMMANDE = NEXT_GFX;
            break;
        default:
            refresh();
            break;
        }
        print_menu(menu_win, highlight);
        if (choice != 0)
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

void Ncurses::createWindow()
{
    initscr();
    clear();
}
void print_menu(WINDOW *menu_win, int highlight)
{
    int x, y, i;

    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}