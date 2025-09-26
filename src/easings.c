#include "easings.h"
#include <math.h>

// A simple easing function: easeOutQuad
// t = current time, b = start value, c = change in value, d = duration
float EaseOutQuad(float t, float b, float c, float d) {
    t /= d;
    return -c * t*(t-2) + b;
}

float EaseInOutCubic(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) return c / 2 * t * t * t + b;
    t -= 2;
    return c / 2 * (t * t * t + 2) + b;
}


float EaseOutElastic(float t, float b, float c, float d) {
    if (t == 0) return b;
    t /= d;
    if (t == 1) return b + c;
    float p = d * 0.3f;
    float a = c;
    float s = p / 4;
    return a * powf(2, -10 * t) * sinf((t * d - s) * (2 * 3.14159265f) / p) + c + b;
}



void InitMover(Mover* mover, Vector2 start, Vector2 end, float duration, EasingFunction easing) {
    mover->start = start;
    mover->end = end;
    mover->duration = duration;
    mover->isMoving = false;
    mover->transitionTime = 0.0f;   
    mover->easing = easing;
}

void InitInflater(Inflater* inflater, float start_radius, float end_radius, float duration, EasingFunction easing) {
    inflater->start_radius = start_radius;
    inflater->end_radius = end_radius;
    inflater->duration = duration;
    inflater->isInflating = false;
    inflater->transitionTime = 0.0f;
    inflater->easing = easing;
}


void UpdateMover(Mover* mover, Circle* circle, float deltaTime) {

        mover->transitionTime += deltaTime;

        if (mover->transitionTime >= mover->duration) {
            mover->isMoving = false;
        } else {
            circle->position.x = mover->easing(mover->transitionTime, mover->start.x, mover->end.x - mover->start.x, mover->duration);
            circle->position.y = mover->easing(mover->transitionTime, mover->start.y, mover->end.y - mover->start.y, mover->duration);
        }
    }   

void UpdateInflater(Inflater* inflater, Circle* circle, float deltaTime) {

    inflater->transitionTime += deltaTime;

    if (inflater->transitionTime >= inflater->duration) {
        inflater->isInflating = false;
    } else {
        circle->radius = inflater->easing(inflater->transitionTime, inflater->start_radius, inflater->end_radius - inflater->start_radius, inflater->duration);
    }
}

