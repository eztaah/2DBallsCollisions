#ifndef __COLLISIONS_MANAGER__
#define __COLLISIONS_MANAGER__

#include "collisions_manager.h"
#include "globals.h"


void HandleCollisionsTwoBalls(Ball *ball1, Ball *ball2);
void HandleCollisionsBallWall(Ball *ballPtr, ie_Rectanglef *boxPtr);
void HandleCollisions(const ie_Rectanglef *box,  Ball *ballsArray, int ballIndex);



#endif