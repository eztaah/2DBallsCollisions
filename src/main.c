#include "globals.h"
#include "engine.h"
#include "collisions_manager.h"
#include <string.h>
#include <stdio.h>
#include <SDL.h>


// ========= GLOBAL VARIABLES & UTILITY FUNCTIONS =========

// ===== Variables =====
// Global
double lastUpdateTimeEvent1 = 0.0f;

// colors array
int colorsArray[6][3] = {
    {232, 248, 245},
    {209, 242, 235},
    {163, 228, 215},
    {118, 215, 196},
    {72, 201, 176},
    {26, 188, 156}
};

// === Functions ===
void CreateBall(Ball *ballsArray, int ballIndex);
void UpdateBall(Ball *ball);

// =========================================================


// WinMain is used on windows
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    ie_InitWindow(screenWidth, screenHeight, "balls");

    ie_SetTargetFPS(165);

    // Setup balls array
    int ballIndex = 0;
    const int BALLS_ARRAY_SIZE = 20;
    Ball ballsArray[BALLS_ARRAY_SIZE];

    // Instancie un rectangle
    const ie_Rectanglef box = {100.0f, 100.0f, 600.0f, 400.0f};



    // ========= GAME LOOP =========
    while (!ie_WindowShouldClose())
    {
        // =========== UPDATE ===========

        // Add a ball if needed 
        if(ie_EventTriggered(1, &lastUpdateTimeEvent1) && (ballIndex <= BALLS_ARRAY_SIZE - 2)) {
            CreateBall(ballsArray, ballIndex);
            ballIndex += 1;
        }
    
        // Update balls
        for(int i=0 ; i<ballIndex ; i++) {
            printf("ballIndex : %d\n", ballIndex);
            printf("i : %d\n\n", i);
            UpdateBall(&ballsArray[i]); 
        }

        // Handle collisions
        HandleCollisions(&box, ballsArray, ballIndex);
        // ==============================


        // =========== DRAW ===========
        // Met le bg en noir
        ie_ClearBackground(ie_darkGrey);

        // Dessine un cercle rempli
        for(int i=0 ; i<ballIndex ; i++) {
            //ie_DrawEmptyCircle(ballsArray[i].px, ballsArray[i].py, ballsArray[i].radius, 2, ballsArray[i].color);
            ie_DrawFilledCircle(ballsArray[i].px, ballsArray[i].py, ballsArray[i].radius, ballsArray[i].color);
        }

        // Dessine un rectangle vide
        ie_DrawRectangleBorder(box.x, box.y, box.w, box.h, ie_offWhite);

        ie_EndDrawing();
        // ============================
    }

    // Destruction de la fenetre et quitter sdl
    ie_CloseWindow();
    return 0;
}





// ============================================ Functions ===================================================
void CreateBall(Ball *ballsArray, int ballIndex)
{
    Ball ball;

    ball.ready = 0;
    ball.keepNotReady = 1;
    //ball.radius = ie_GetRandomNumber(5, 15);
    ball.radius = ie_GetRandomNumber(15, 20);
    ball.mass = ball.radius;

    ball.px = 800 / 2.0f - ball.radius;        // todo : getwidth
    ball.py = 600 / 2.0f - ball.radius;

    ball.vx = ie_GetRandomNumber(-5, 5) * 15.0f;
    ball.vy = ie_GetRandomNumber(-5, 5) * 15.0f;

    ball.ax = 0.0f;
    ball.ay = 0.0f;

    int number = ie_GetRandomNumber(0, 5);
    memcpy(&ball.color, colorsArray[number], sizeof(colorsArray[number]));   // Copie bytes from source to destination   

    ballsArray[ballIndex] = ball;
}


void UpdateBall(Ball *ball)
{
    float dt = ie_GetFrameTime();

    // calculate velocity
    ball->vx = ball->vx + (ball->ax * dt);
    ball->vy = ball->vy + (ball->ay * dt);

    // Calculate position 
    ball->px = ball->px + (ball->vx * dt);
    ball->py = ball->py + (ball->vy * dt);
}