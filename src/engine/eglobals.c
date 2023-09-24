#include "eglobals.h"
#include "ebase.h"


// === Window ===
int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;
SDL_Window *windowPtr = NULL;
SDL_Renderer *rendererPtr = NULL;

// === fps ===
Uint32 targetFPS = 60;


void ie_SDL_ExitWithError(const char *message)
{
    SDL_Log("%s%s\n", message, SDL_GetError());
    ie_CloseWindow();
    exit(1);   
}
