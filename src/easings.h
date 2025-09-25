#ifndef EASINGS_H
#define EASINGS_H

#include "raylib.h"

typedef struct Mover {
    Vector2 start;
    Vector2 end;
    float start_time;
    float duration;
    bool isMoving;
    float transitionTime;
} Mover;

void InitMover(Mover* mover, Vector2 start, Vector2 end, float duration);
float EaseOutQuad(float t, float b, float c, float d);

#endif