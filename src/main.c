#include "raylib.h"
#include "circle.h"
#include "easings.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int main(void) {


	// Initialize window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pezzza's transitions");
	SetTargetFPS(60);

	// Init  here
    Circle circle = { .position = { 100, 100 }, .radius = 50, .color = RED };
    
    Mover mover; // create mover object that contains time and position to move
    InitMover( &mover, circle.position,  (Vector2){400, 400},  1.0f);

    Inflater inflater;
    InitInflater(&inflater, circle.radius, 100.0f, 1.0f);



	// Game loop
	while(!WindowShouldClose()) {
		float deltaTime = GetFrameTime(); // returns time in seconds of each frame

		// Update

        // Increase the circle size by 2
		if (IsKeyPressed(KEY_I)) {
            inflater.start_radius = circle.radius;
            inflater.end_radius = circle.radius * 2;
            inflater.transitionTime = 0.0f;
            inflater.isInflating = true;
        }

        if (inflater.isInflating) {
            inflater.transitionTime += deltaTime;

            if (inflater.transitionTime >= inflater.duration) {
                circle.radius = inflater.end_radius;
                inflater.isInflating = false;
            } else {
                circle.radius = EaseOutQuad(inflater.transitionTime, inflater.start_radius, inflater.end_radius - inflater.start_radius, inflater.duration);
            }
        }

        // Decrease the circle size by 2
        if (IsKeyPressed(KEY_D)) {
            inflater.start_radius = circle.radius;

            if (circle.radius > 1 ) {
                inflater.end_radius = circle.radius / 2;
            } else {
                inflater.end_radius = 1.0f;
            }
            
            inflater.transitionTime = 0.0f;
            inflater.isInflating = true;
        }

        if (inflater.isInflating) {
            inflater.transitionTime += deltaTime;

            if (inflater.transitionTime >= inflater.duration) {
                circle.radius = inflater.end_radius;
                inflater.isInflating = false;
            } else {
                circle.radius = EaseOutQuad(inflater.transitionTime, inflater.start_radius, inflater.end_radius - inflater.start_radius, inflater.duration);
            }
        }

        // Move the circle to the mouse position smoothly
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mover.start = circle.position;
            mover.end = GetMousePosition();
            mover.transitionTime = 0.0f;
            mover.isMoving = true;
        }

        if (mover.isMoving) {
            mover.transitionTime += deltaTime;

            if (mover.transitionTime >= mover.duration) {
                circle.position = mover.end;
                mover.isMoving = false;
            } else {

              /*
              arguments:
                t = current time
                b = start value
                c = change in value
                d = duration
              */

                circle.position.x = EaseOutQuad(mover.transitionTime, mover.start.x, mover.end.x - mover.start.x, mover.duration);
                circle.position.y = EaseOutQuad(mover.transitionTime, mover.start.y, mover.end.y - mover.start.y, mover.duration);

            }
        }   

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		DrawMyCircle(&circle);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}