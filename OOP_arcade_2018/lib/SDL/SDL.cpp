/*
** EPITECH PROJECT, 2019
** SDL.hpp
** File description:
** SDL
*/

#include "SDL.hpp"

SDL::SDL()
{
}

SDL::~SDL()
{
}

void SDL::gfxLoop(IGfx::ACTION &COMMANDE)
{
    SDL::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    COMMANDE = OTHER;

    if (!renderer) {
        std::cout << "Renderer could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        // Declare rect of square
        SDL_Rect squareRect;

        // Square dimensions: Half of the min(SCREEN_WIDTH, SCREEN_HEIGHT)
        squareRect.w = std::min(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;
        squareRect.h = std::min(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;

        // Square position: In the middle of the screen
        squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
        squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;

        // Event loop exit flag
        // Event loop
        while (!quit) {

            // Wait indefinitely for the next available event
            getEvents(COMMANDE);
            if (COMMANDE == PREV_GFX || COMMANDE == NEXT_GFX) {
            }

            // Initialize renderer color white for the background
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            // Clear screen
            SDL_RenderClear(renderer);

            // Set renderer color red to draw the square
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

            // Draw filled square
            SDL_RenderFillRect(renderer, &squareRect);

            // Update screen
            SDL_RenderPresent(renderer);
        }
        // Destroy renderer
    SDL_DestroyRenderer(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDL::getEvents(IGfx::ACTION &COMMANDE)
{
    SDL_Event e;

    SDL_WaitEvent(&e);
    // User requests quit
    if (e.type == SDL_QUIT) {
        quit = true;
    }
    // lib Handler
    if (e.key.keysym.sym == SDLK_1) {
        quit = true;
        COMMANDE = PREV_GFX;
    }
    if (e.key.keysym.sym == SDLK_2) {
        quit = true;
        COMMANDE = NEXT_GFX;
    }
}

void SDL::createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    }
    // Create window
    window = SDL_CreateWindow("Basic C++ SDL project",

        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
        exit(84);
    }
}