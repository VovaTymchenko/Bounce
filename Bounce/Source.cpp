#include <iostream>
#include "Renderer.h"
#include "Circle.h"
#include "Ball.h"
//#include <chrono>
//#include <thread>



/*
things to consider :
	* - i would like to dig deeper into "how do i increase fps here?", most likely changing the way i draw frames AND/OR make them (think double buffering)
	- i might want to change how i store pointers to circles and balls in the renderer (so that they are not separate)
	- Ball::Bounce() is not looking good, im pretty sure i can come up with a pretty solution if i put some thoughts into that
	- adding a scale value for rendering might be a good idea - if i want more objects to display preserving relative distance between them, multiplying x and y coordinates in the MakeFrame() loop

	* frames are still flickering, but i think it is a limitaiton of console printing

P.S: for the full list address the cereal lists
*/



int main()
{
	Circle* circle1 = new Circle();
	//AddCircle(circle1);

	Circle* circle2 = new Circle(90, 90, 0, 30);
	//AddCircle(circle2);

	Ball* ball2 = new Ball(30, 70, 8, 2.4, -4.7);
	AddBall(ball2);

	Ball* ball3 = new Ball(130, 130, 6, 1.4, 2.2);
	AddBall(ball3);

	Ball* ball4 = new Ball(50, 50, 10, 5.4, 3.7);
	AddBall(ball4);

	Ball* ball5 = new Ball(110, 130, 6, -1.4, 7.2);
	AddBall(ball5);

	Ball* ball6 = new Ball(10, 9, 8, 2.4, -4.7);
	AddBall(ball6);

	Ball* ball7 = new Ball(150, 150, 6, 1.4, 2.2);
	AddBall(ball7);

	Ball* ball8 = new Ball(70, 20, 10, 5.4, 3.7);
	AddBall(ball8);

	Ball* ball9 = new Ball(11, 100, 6, -1.4, 7.2);
	AddBall(ball9);

	while (true) //main loop - redraws frames
	{
		MakeFrame();
		DrawFrame();
	}

	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return 0;
}