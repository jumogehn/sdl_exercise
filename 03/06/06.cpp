#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec wav_spec;
    Uint8* wav_buffer;
    Uint32 wav_length;

    if (SDL_LoadWAV("example.wav", &wav_spec, &wav_buffer, &wav_length) == NULL) {
        fprintf(stderr, "Failed to load WAV file: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_AudioDeviceID dev = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
    if (dev == 0) {
        fprintf(stderr, "Failed to open audio device: %s\n", SDL_GetError());
        exit(1);
    }

    int success = SDL_QueueAudio(dev, wav_buffer, wav_length);
    if (success != 0) {
        fprintf(stderr, "Failed to queue audio: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_PauseAudioDevice(dev, 0);

    SDL_Delay(5000); // Wait for 5 seconds to play the entire WAV file

    SDL_CloseAudioDevice(dev);
    SDL_FreeWAV(wav_buffer);
    SDL_Quit();

    return 0;
}

