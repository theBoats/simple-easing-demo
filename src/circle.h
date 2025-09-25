#ifndef CIRCLE_H
#define CIRCLE_H

#include "raylib.h"

typedef struct Circle {
	Vector2 position;
	float radius;
	Color color;
} Circle;

void DrawMyCircle(Circle* circle);
void SetCirclePosition(Circle* circle, Vector2 newPosition);

#endif
