#ifndef __EBASE__
#define __EBASE__

#include "SDL.h"


// ========= WINDOW =========
void ie_InitWindow(int width, int height, const char *title);
int ie_WindowShouldClose();
void ie_CloseWindow();


// ========= TIME =========
double ie_GetTime();
int ie_EventTriggered(double interval, double *lastUpdateTime);

// ========= FPS =========
void ie_SetTargetFPS(const Uint32 fps);
float ie_GetFrameTime();


// ========= STRUCTURES =========
typedef struct Rectangle {
    float x, y;
    float w, h;
} ie_Rectanglef;


// ========= COLORS =========
extern int ie_darkGrey[3];
extern int ie_offWhite[3];
extern int ie_purple[3];
extern int ie_skyBlue[3];
extern int ie_red[3];
extern int ie_green[3];


#endif