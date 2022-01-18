#include <stdio.h>
#include <SDL2/SDL.h>

#define Width 600
#define Height 700
#define Frame 60

void event_loop();

void Draw();

SDL_Renderer *renderer;

SDL_Window *win;

SDL_Texture *tex;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init video ,%s", SDL_GetError());
        return 1;
    }

    win = SDL_CreateWindow(
            "Hello World",// title
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, //position
            Width, Height, // width and height
            SDL_WINDOW_SHOWN); // a flag?
    if (win == NULL) {
        SDL_Log("can not create a window, %s", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);
    if (renderer == NULL){
        SDL_Log("Can not create a renderer");
        return 1;
    }

    SDL_Surface *img = SDL_LoadBMP("zhongzhong.bmp");
    tex = SDL_CreateTextureFromSurface(renderer,img);
    event_loop();
    SDL_FreeSurface(img);
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win); // equal to free
    return 0;
}

void event_loop() {
    while (1) {
        uint32_t begin = SDL_GetTicks();
        Draw();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            }
        }
        uint32_t current = SDL_GetTicks();
        uint32_t cost = current - begin;
        long int delay = 1000 / Frame - cost;
        SDL_UpdateWindowSurface(win);
        if (delay > 0) {
            SDL_Delay(delay);
        }
    }
}

void Draw() {
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    int w,h;
    SDL_QueryTexture(tex,NULL,NULL,&w,&h);
    SDL_Rect src = {0,0,w,h};
    //static double angle = 0;
    //angle += 0.5;
    SDL_RenderCopyEx(renderer,tex,&src,&src,0,NULL,SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
    SDL_RenderPresent(renderer);
}








