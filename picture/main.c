#include <stdio.h>
#include <SDL2/SDL.h>
#define Width 400
#define Height 300
void event_loop ();
int main() {
    if (SDL_Init(SDL_INIT_VIDEO)) {//init a window , if there's no problem, it's return is 0
        SDL_Log("Can not init video ,%s", SDL_GetError());//SDL_Log is printf ,GetError get the wrong information
        return 1;
    }
    // found a simple window
    SDL_Window *win = SDL_CreateWindow(
            "Hello World",// title
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, //position
            Width, Height, // width and height
            SDL_WINDOW_SHOWN); // a flag?
    if (win == NULL) {
        SDL_Log("can not create a window, %s", SDL_GetError());
        return 1;
    }
    //SDL_Delay(3000);// equal to sleep

    SDL_Surface *screen = SDL_GetWindowSurface(win);// get the surface of the window
    SDL_Rect background = {0,0,Width,Height};// a struct position and size
    SDL_FillRect(screen,&background,0xff0000ff);//ARGB ,A is not transparent ,ff is complete
    SDL_Rect small_color = {0,0,100,100};
    SDL_FillRect(screen,&small_color,0xff00ff00);
    SDL_UpdateWindowSurface(win);

    event_loop();

    SDL_DestroyWindow(win); // equal to free
    return 0;
}
void event_loop (){
    while (1){
        SDL_Event event;
        if (SDL_PollEvent(&event)){// PollEvent  if there's a event ,return 1
            //printf("event ,%d\n",event.type);
            if (event.type == SDL_QUIT){ // equal to this event
                break;
            }
        }
    }
}