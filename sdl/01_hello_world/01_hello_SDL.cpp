#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]){
    // window
    SDL_Window* window = NULL;

    // surface
    SDL_Surface* screenSurface = NULL;

    // init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL_Err: %s\n", SDL_GetError()); // init err
    }
    else{
        // create window
        window = SDL_CreateWindow("hello window", 
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED,  
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
                );
        if(window == NULL){
            printf("SDL_Err: %s\n", SDL_GetError()); // window err
        }
    }
    return 0;
}
