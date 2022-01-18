#include <stdio.h>
#include <SDL2/SDL.h>
#define Width 600
#define Height 500
#define Frame 60
void event_loop (SDL_Surface *screen , SDL_Window *win);
void Draw ( SDL_Surface *screen , SDL_Window *win);
struct SDL_Surface *img;
int main() {
    if (SDL_Init(SDL_INIT_VIDEO)) {//init a window , if there's no problem, it's return is 0
        SDL_Log("Can not init video ,%s", SDL_GetError());//SDL_Log is printf ,GetError get the wrong information
        return 1;
    }
    SDL_Window *win = SDL_CreateWindow(
            "Hello World",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            Width, Height,
            SDL_WINDOW_SHOWN);
    if (win == NULL) {
        SDL_Log("can not create a window, %s", SDL_GetError());
        return 1;
    }

    img = SDL_LoadBMP("zhongzhong.bmp");
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    event_loop(screen,win);
    SDL_FreeSurface(img);
    SDL_DestroyWindow(win);
    return 0;
}
void event_loop (SDL_Surface *screen , SDL_Window *win){
    while (1){
        Draw(screen,win);
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                return;
            }
        }
    }
}
void Draw ( SDL_Surface *screen , SDL_Window *win){
    SDL_Rect src = {0,0,img->w,img->h};
    SDL_BlitSurface(img,&src,screen,&src);
    SDL_UpdateWindowSurface(win);
}


