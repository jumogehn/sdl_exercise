#include <SDL2/SDL.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &pWindow, &pRenderer) < 0)
    {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Surface *pHellowBMP = SDL_LoadBMP("hello.bmp");
    if (pHellowBMP == 0)
    {
        SDL_DestroyRenderer(pRenderer);
        SDL_DestroyWindow(pWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pHellowBMP);

    SDL_FreeSurface(pHellowBMP);
    if (pTexture == 0)
    {
        SDL_DestroyRenderer(pRenderer);
        SDL_DestroyWindow(pWindow);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
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

        SDL_RenderClear(pRenderer);
        SDL_RenderCopy(pRenderer, pTexture, NULL, NULL);
        SDL_RenderPresent(pRenderer);
    }

    SDL_DestroyTexture(pTexture);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}

