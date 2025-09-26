#ifndef EASINGS_H
#define EASINGS_H

#include "raylib.h"
#include "circle.h"
/*

A way to move between different easing functions is to define pointer to the easing function

*/

typedef float (*EasingFunction)(float t, float b, float c, float d);

typedef struct Mover {
    Vector2 start;
    Vector2 end;
    float duration;
    bool isMoving;
    float transitionTime;
    EasingFunction easing; // function pointer to easing function
} Mover;


typedef struct Inflater {
    float start_radius;
    float end_radius;
    float duration;
    bool isInflating;
    float transitionTime;
    EasingFunction easing; // function pointer to easing function

} Inflater;




// function prototypes
void InitMover(Mover* mover, Vector2 start, Vector2 end, float duration, EasingFunction easing);
void InitInflater(Inflater* inflater, float start_radius, float end_radius, float duration, EasingFunction easing);
void UpdateMover(Mover* mover, Circle* circle, float deltaTime);
void UpdateInflater(Inflater* inflater, Circle* circle, float deltaTime);   
float EaseOutQuad(float t, float b, float c, float d);
float EaseInOutCubic(float t, float b, float c, float d);
float EaseOutElastic(float t, float b, float c, float d);

/*
              arguments:
                t = current time
                b = start value
                c = change in value
                d = duration
              */








#endif