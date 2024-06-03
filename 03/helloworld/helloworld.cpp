
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 0;
    }


    SDL_Window* pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (pWindow == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Surface* pScreenSurface = SDL_GetWindowSurface(pWindow);

    SDL_Surface* pHellowBMP = SDL_LoadBMP("hello.bmp");
    if (pHellowBMP == 0){

        SDL_DestroyWindow(pWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return 0;
    }


    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_BlitSurface(pHellowBMP, NULL, pScreenSurface, NULL);

        SDL_UpdateWindowSurface(pWindow);


    }

    SDL_FreeSurface(pHellowBMP);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}


