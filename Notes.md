# Pezzza's work

## How to animate anything

Animations aka Transitions; Interpolation between two states

Instead of an instant transition use a time interval, default one second
For instance to go from point A to point B; C = A + delta * t; where t is between 0 and 1.
At t = 0, C = A
At t = 1, C = B 
delta is the change i.e. B - A

We can replace t with an 'easing' function. That outputs a value in [0,1]. i.e. f(0) = 0, f(1) = 1
Examples can be found on easings.net
- linear
- EaseInOutExponential
- EaseInBack
- EaseOutBack
- EaseOutElastic

We can apply these functions to any vector, allowing control of things like:
- Position
- Rotation (angle)
- Scale
- Colour
- etc.

## Implementation

Create a draw function with a parameter controlled by a variable. E.g. radius of a circle

Create an interpolator object to handle the interpolation with:
- a starting value (e.g. initial radius)
- an end value (e.g. final radius)
- a duration (how long the animation should take); hardcoded 1s for now
- a boolean to check if the animation is finished
- a transition time (how long the animation has been running)
- [not implemented] a start time (when the animation began);  this is handled by deltaTime atm



