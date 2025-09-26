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
    InitMover( &mover, circle.position,  (Vector2){400, 400},  1.0f, EaseOutQuad);

    Inflater inflater;
    InitInflater(&inflater, circle.radius, 100.0f, 1.0f, EaseOutQuad);



	// Game loop
	while(!WindowShouldClose()) {
		float deltaTime = GetFrameTime(); // returns time in seconds of each frame

		// Update

        // Check for input

        // Increase the circle size by 2
		if (IsKeyPressed(KEY_I)) {
            inflater.start_radius = circle.radius;
            inflater.end_radius = circle.radius * 2;
            inflater.transitionTime = 0.0f;
            inflater.isInflating = true;
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

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mover.isMoving = true;
            mover.start = circle.position;
            mover.end = GetMousePosition();
            mover.transitionTime = 0.0f;
        }

        // Update movers
        if (mover.isMoving) {
            UpdateMover(&mover, &circle, deltaTime);
        }

        if (inflater.isInflating) {
            UpdateInflater(&inflater, &circle, deltaTime);
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