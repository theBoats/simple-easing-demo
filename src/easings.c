#include "easings.h"

// A simple easing function: easeOutQuad
// t = current time, b = start value, c = change in value, d = duration
float EaseOutQuad(float t, float b, float c, float d) {
    t /= d;
    return -c * t*(t-2) + b;
}


void InitMover(Mover* mover, Vector2 start, Vector2 end, float duration) {
    mover->start = start;
    mover->end = end;
    mover->start_time = GetTime();
    mover->duration = duration;
    mover->isMoving = false;
    mover->transitionTime = 0.0f;   
}
