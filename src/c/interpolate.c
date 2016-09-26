//
// Created by harrison on 9/26/2016.
//

#include <math.h>
#include "../headers/interpolate.h"

double interpolate_stepwise_nearest(int tCount, double* tValues, double* yValues, double t) {
    int i, prevI = 0, nextI = 0;
    double prevT = tValues[0], nextT = 0;

    if (tCount == 1) {
        return yValues[0];
    }

    for (i = 1; i < tCount; i++) {
        nextI = i;
        nextT = tValues[i];

        if (t >= prevT && t <= nextT)
            break;

        prevT = nextT;
        prevI = nextI;
    }

    if (fabs(t - nextT) < fabs(t - prevT)) {
        return yValues[nextI];
    } else {
        return yValues[prevI];
    }
}

double interpolate_linear(int tCount, double* tValues, double* yValues, double t) {
    int i, prevI = 0, nextI = 0;
    double prevT = tValues[0], nextT = 0;

    if (tCount == 1) {
        return yValues[0];
    }

    for (i = 1; i < tCount; i++) {
        nextI = i;
        nextT = tValues[i];

        if (t >= prevT && t <= nextT)
            break;

        prevT = nextT;
        prevI = nextI;
    }

    return yValues[prevI] + (t-prevT) * (yValues[nextI] - yValues[prevI]) / (nextT-prevT);
}

double interpolate(InterpolationType iType, int tCount, double* tValues, double* yValues, double t) {

    if (tCount == 0)
        return 0;

    switch (iType) {
        case INTERPOLATE_STEPWISE_NEAREST:
            return interpolate_stepwise_nearest(tCount, tValues, yValues, t);
        case INTERPOLATE_LINEAR:
            return interpolate_linear(tCount, tValues, yValues, t);
    }

    return 0;

}