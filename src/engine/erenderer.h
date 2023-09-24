#ifndef __ERENDERER__
#define __ERENDERER__

#include <SDL.h>

// === Drawing ===
void ie_ClearBackground(int color[3]);
void ie_DrawEmptyCircle(int x_center, int y_center, int radius, int borderWidth, int color[3]);
void ie_DrawFilledCircle(int x_center, int y_center, int radius, int color[3]);
void ie_DrawRectangleBorder(int x, int y, int width, int height, int color[3]);
void ie_EndDrawing();



#endif