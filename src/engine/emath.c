#include "emath.h"
#include <math.h>
#include <stdlib.h>


// ========= FUNDAMENTAL =======
double ie_sqrt(double x) {
    return sqrt(x);
}
int ie_abs(int x) {
    return abs(x);
}


// ========= GEOMETRY =======
float ie_CalculateBallDistance(const Ball *ball1, const Ball *ball2)
{
    float dx = ball1->px - ball2->px;
    float dy = ball1->py - ball2->py;
    float distance = ie_sqrt(dx * dx + dy * dy);

    return distance;
}


// ========= RANDOM =======
int ie_GetRandomNumber(int min, int max)
{
    int randomNumber = min + rand() % (max + 1 - min);
    return randomNumber;
}