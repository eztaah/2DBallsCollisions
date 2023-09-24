#include "ebase.h"
#include "eglobals.h"
#include "erenderer.h"
#include <stdio.h>
#include <time.h>



// === variables ===
// FPS
Uint32 lastFrameTime;
Uint32 frameStart = 0;
Uint32 currentFrameTime = 0; 
float reelFrameTime;   // in seconds




// ========= WINDOW =========
void ie_InitWindow(int width, int height, const char *title)
{
    // ====== Setup SDL, window, renderer ======
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        ie_SDL_ExitWithError("ERREUR : Initialisation de fenetre echoue");

    // Creation de la fenetre
    windowPtr = SDL_CreateWindow(title,
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                               width, height, 
                               0);
    if(windowPtr == NULL)
        ie_SDL_ExitWithError("ERREUR : Creation de fenetre echoué");

    // Creation rendererPtr 
    rendererPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_SOFTWARE);
    if(rendererPtr == NULL)
        ie_SDL_ExitWithError("Creation de rendu echoue");


    // ====== Create seed for random numbers ======
    srand(time(NULL));
}

int ie_WindowShouldClose()
{
    // Handle FPS
    const Uint32 frameDelay = 1000 / targetFPS;  // in milliseconds
    currentFrameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > currentFrameTime) {
        SDL_Delay(frameDelay - currentFrameTime);
        reelFrameTime = 1.0f / 60.0f;
    }
    else {
        reelFrameTime = currentFrameTime / 1000.0f;
    }


    // ====== EVENTS HANDLING ======
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return 1;
        
        default:
            break;
        }
    }
    // ==============================

    // Start the chrono for fps
    frameStart = SDL_GetTicks();

    return 0;
}

void ie_CloseWindow()
{
    SDL_DestroyRenderer(rendererPtr);
    SDL_DestroyWindow(windowPtr);
    SDL_Quit();
}



// ==== TIME ====
double ie_GetTime() {
    return (double)SDL_GetTicks() / 1000.0; // Convert milliseconds to seconds
}

int ie_EventTriggered(double interval, double *lastUpdateTime) {
    double currentTime = ie_GetTime();
    if (currentTime - *lastUpdateTime >= interval) {
        *lastUpdateTime = currentTime;
        return 1;
    }
    return 0;
}


// ========= FPS =========
void ie_SetTargetFPS(const Uint32 fps)
{
    targetFPS = fps;
}

float ie_GetFrameTime() {
    return 1.0f / targetFPS;
}





// === Colors ===
int ie_darkGrey[3] = {37, 37, 37};
int ie_offWhite[3] = {236, 236, 236};
int ie_purple[3] = {178, 162, 234};
int ie_skyBlue[3] = {132, 203, 193};
int ie_red[3] = {224, 123, 123};
int ie_green[3] = {166, 223, 141};