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
    mover->duration = duration;
    mover->isMoving = false;
    mover->transitionTime = 0.0f;   
}

void InitInflater(Inflater* inflater, float start_radius, float end_radius, float duration) {
    inflater->start_radius = start_radius;
    inflater->end_radius = end_radius;
    inflater->duration = duration;
    inflater->isInflating = false;
    inflater->transitionTime = 0.0f;
}
