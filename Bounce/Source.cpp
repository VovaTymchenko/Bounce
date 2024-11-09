#include <iostream>
#include "Renderer.h"
#include "Circle.h"
#include "Ball.h"
//#include <chrono>
//#include <thread>



/*
things to consider :
	- i might want to change how i store pointers to circles and balls in the renderer (so that they are not separate)
	- i would like to dig deeper into "how do i increase fps here?", most likely changing the way i draw frames AND/OR make them (think double buffering)
	- Ball::Bounce() is not looking good, im pretty sure i can come up with a pretty solution if i put some thoughts into that
	- adding a scale value for rendering might be a good idea - if i want more objects to display preserving relative distance between them, multiplying x and y coordinates in the MakeFrame() loop

P.S: for the full list address the cereal box lists
*/



int main()
{
	Circle* circle1 = new Circle();
	AddCircle(circle1);

	Circle* circle2 = new Circle(90, 90, 0, 30);
	AddCircle(circle2);
	
	Ball* ball1 = new Ball();
	AddBall(ball1);

	Ball* ball2 = new Ball(15, 15, 7, 2, 7);
	AddBall(ball2);

	while (true) //main loop - redraws frames
	{
		MakeFrame();
		DrawFrame();
	}

	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return 0;
}