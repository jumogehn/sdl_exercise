#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("SDL2 Mouse Input", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    bool quit = false;
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "Mouse button pressed: " << static_cast<int>(event.button.button) << std::endl;
                std::cout << "Mouse position: (" << event.button.x << ", " << event.button.y << ")" << std::endl;
                break;
            case SDL_MOUSEBUTTONUP:
                std::cout << "Mouse button released: " << static_cast<int>(event.button.button) << std::endl;
                std::cout << "Mouse position: (" << event.button.x << ", " << event.button.y << ")" << std::endl;
                break;
            case SDL_MOUSEMOTION:
                std::cout << "Mouse moved: (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
                break;
            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

