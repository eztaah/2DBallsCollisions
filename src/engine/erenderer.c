#include "erenderer.h"
#include "eglobals.h"
#include <math.h>


// === Drawing ===
void ie_ClearBackground(int color[3])
{
    // Change color
    if(SDL_SetRenderDrawColor(rendererPtr, color[0], color[1], color[2], SDL_ALPHA_OPAQUE) != 0)
        ie_SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

    // Nettoie la fenetre
    SDL_RenderClear(rendererPtr);
}

void ie_DrawEmptyCircle(int x_center, int y_center, int radius, int borderWidth, int color[3])
{
    // Change color
    if(SDL_SetRenderDrawColor(rendererPtr, color[0], color[1], color[2], SDL_ALPHA_OPAQUE) != 0)
        ie_SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

    // Draw circle with variable border width
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            int distanceSquared = dx * dx + dy * dy;

            if (distanceSquared <= (radius * radius) && distanceSquared >= ((radius - borderWidth) * (radius - borderWidth)))
            {
                SDL_RenderDrawPoint(rendererPtr, x_center + dx, y_center + dy);
            }
        }
    }
}

void ie_DrawFilledCircle(int x_center, int y_center, int radius, int color[3])
{
    // Change color
    if(SDL_SetRenderDrawColor(rendererPtr, color[0], color[1], color[2], SDL_ALPHA_OPAQUE) != 0)
        ie_SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

    // Draw circle
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(rendererPtr, x_center + dx, y_center + dy);
            }
        }
    }
}  

void ie_DrawRectangleBorder(int x, int y, int width, int height, int color[3])
{
    // Change color
    if(SDL_SetRenderDrawColor(rendererPtr, color[0], color[1], color[2], SDL_ALPHA_OPAQUE) != 0)
        ie_SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

    // Créé un rectangle
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;

    SDL_RenderDrawRect(rendererPtr, &rectangle);
}

void ie_EndDrawing()
{
    // Met à jour la fenetre
    SDL_RenderPresent(rendererPtr);
}