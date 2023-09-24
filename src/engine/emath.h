#ifndef __EMATH__
#define __EMATH__

#include "globals.h"


// ========= FUNDAMENTAL =======
double ie_sqrt(double x);
int ie_abs(int x);


// ========= GEOMETRY =======
float ie_CalculateBallDistance(const Ball *ball1, const Ball *ball2);


// ========= RANDOM =======
int ie_GetRandomNumber(int min, int max);


#endif