#include "circle.h"

void DrawMyCircle(Circle* circle) {
	DrawCircleV(circle->position, circle->radius, circle->color);
}

void SetCirclePosition(Circle* circle, Vector2 newPosition) {
    circle->position = newPosition;
}

