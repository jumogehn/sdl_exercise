#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    float x, y;
    float vx, vy;
    int lifetime;
} particle_t;

void spawn_particle(particle_t* particle) {
    particle->x = rand() % SCREEN_WIDTH;
    particle->y = rand() % SCREEN_HEIGHT;
    particle->vx = ((float)rand() / RAND_MAX) * 2 - 1;
    particle->vy = ((float)rand() / RAND_MAX) * 2 - 1;
    particle->lifetime = 60 + rand() % 60;
}

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;
    particle_t particles[100];

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Particle System",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    for (int i = 0; i < 100; i++) {
        spawn_particle(&particles[i]);
    }

    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit(0);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 100; i++) {
            particle_t* particle = &particles[i];
            particle->x += particle->vx;
            particle->y += particle->vy;
            particle->lifetime--;

            if (particle->lifetime <= 0) {
                spawn_particle(particle);
            }

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawPoint(renderer, particle->x, particle->y);
        }

        SDL_RenderPresent(renderer);
    }

    return 0;
}

