#ifndef __EGLOBALS__
#define __EGLOBALS__

#include "SDL.h"


// === Window ===
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern SDL_Window *windowPtr;
extern SDL_Renderer *rendererPtr;

// === fps ===
extern Uint32 targetFPS;


void ie_SDL_ExitWithError(const char *message);


#endif