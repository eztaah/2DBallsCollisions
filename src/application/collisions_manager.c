#include "engine.h"



void HandleCollisionsTwoBalls(Ball *ball1, Ball *ball2)
{
    // Calculate the distance between the balls
    float dx = ball1->px - ball2->px;
    float dy = ball1->py - ball2->py;
    float distance = ie_CalculateBallDistance(ball1, ball2);    // TODO: improve that

    // if collisions
    if(distance <= ball1->radius + ball2->radius)
    {
        // if ball ready
        if(ball1->ready && ball2->ready)    // TODO: solve if if
        {
            // if the ball is ready
            float m1 = ball1->mass;
            float m2 = ball2->mass;

            float vx1 = ball1->vx;
            float vy1 = ball1->vy;
            float vx2 = ball2->vx;
            float vy2 = ball2->vy;

            // Calcul de la nouvelle vitesse pour la balle 1
            ball1->vx = vx1 - (2 * m2 / (m1 + m2)) * ((vx1 - vx2) * dx + (vy1 - vy2) * dy) / (distance * distance) * dx;
            ball1->vy = vy1 - (2 * m2 / (m1 + m2)) * ((vx1 - vx2) * dx + (vy1 - vy2) * dy) / (distance * distance) * dy;

            // Calcul de la nouvelle vitesse pour la balle 2
            ball2->vx = vx2 - (2 * m1 / (m1 + m2)) * ((vx2 - vx1) * -dx + (vy2 - vy1) * -dy) / (distance * distance) * -dx;
            ball2->vy = vy2 - (2 * m1 / (m1 + m2)) * ((vx2 - vx1) * -dx + (vy2 - vy1) * -dy) / (distance * distance) * -dy;
        }
        if(!ball1->ready)
            ball1->keepNotReady = 1;
             
        if(!ball2->ready)
            ball2->keepNotReady = 1;
    }
}


void HandleCollisionsBallWall(Ball *ball, const ie_Rectanglef *box)
{
    // Collision logic for the box
    // Top, bottom
    if(ball->px - ball->radius < box->x) {
        ball->px = ball->radius + box->x;
        ball->vx = -ball->vx;
    }
    else if(ball->px + ball->radius > box->x + box->w) {
        ball->px = box->x + box->w - ball->radius;
        ball->vx = -ball->vx;
    }
    else if(ball->py - ball->radius < box->y) {
        ball->py = ball->radius + box->y;
        ball->vy = -ball->vy;
    }
    else if(ball->py + ball->radius > box->y + box->h) {
        ball->py = box->y + box->h - ball->radius;
        ball->vy = -ball->vy;
    }
}


void HandleCollisions(const ie_Rectanglef *box,  Ball *ballsArray, int ballIndex)
{
    // Handle collisions wall
    for(int i=0 ; i<ballIndex ; i++) {
        HandleCollisionsBallWall(&ballsArray[i], box);
    }

    // ball-ball
    for(int i=0 ; i<ballIndex ; i++) {
        ballsArray[i].keepNotReady = 0;
    }



    for(int i=0 ; i<ballIndex ; i++) {
        for(int k=i+1 ; k<ballIndex ; k++)
            HandleCollisionsTwoBalls(&ballsArray[i], &ballsArray[k]);
    }
    
    for(int i=0 ; i<ballIndex ; i++) {
        if(ballsArray[i].keepNotReady == 0)
        {
            ballsArray[i].ready = 1;
            //memcpy(ballsArray[i].color, ie_skyBlue, sizeof(ie_skyBlue));   // Copie bytes from source to destination   colorsArray[ie_GetRandomNumber(0, 2)]

        }
    }
}


