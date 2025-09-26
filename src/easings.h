#ifndef EASINGS_H
#define EASINGS_H

#include "raylib.h"

typedef struct Mover {
    Vector2 start;
    Vector2 end;
    // float start_time;
    float duration;
    bool isMoving;
    float transitionTime;
} Mover;


typedef struct Inflater {
    float start_radius;
    float end_radius;
    // float start_time;
    float duration;
    bool isInflating;
    float transitionTime;
} Inflater;


// function prototypes
void InitMover(Mover* mover, Vector2 start, Vector2 end, float duration);
void InitInflater(Inflater* inflater, float start_radius, float end_radius, float duration);
float EaseOutQuad(float t, float b, float c, float d);
/*
              arguments:
                t = current time
                b = start value
                c = change in value
                d = duration
              */



#endif