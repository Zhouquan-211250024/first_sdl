#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#define Width 500
#define Height 500
#define Frame 60
#define Font_size 32
void event_loop (SDL_Surface *screen , SDL_Window *win);
void Draw ( SDL_Surface *screen , SDL_Window *win);

TTF_Font *font;
int main() {
    if ( TTF_Init()){
        SDL_Log("The font is wrong , %s", SDL_GetError());
        return 1;
    }
   if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init video ,%s", SDL_GetError());
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
    font = TTF_OpenFont("font.ttf",Font_size);
    if ( font == NULL){
        SDL_Log("Can not open font");
        return 1;
    }
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    event_loop(screen,win);
    TTF_CloseFont(font);
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
    SDL_Color color = {255,255,255,255};
    SDL_Surface  * text = TTF_RenderUTF8_Blended(font,"zhouquan",color);
    SDL_Rect src = {0,0,text->w,text->h};
    SDL_Rect des = {150,150,text->w,text->h};
    SDL_BlitSurface(text,&src,screen,&des);
    SDL_FreeSurface(text);
    SDL_UpdateWindowSurface(win);
}


