#ifndef __GLOBALS__
#define __GLOBALS__


typedef struct Ball {
    int keepNotReady;
    int ready;
    float px, py;
    float vx, vy;
    float ax, ay;
    int radius;
    int mass;
    int color[3];
} Ball;


#endif