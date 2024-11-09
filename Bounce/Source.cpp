#include <iostream>
#include "Renderer.h"
#include "Circle.h"
#include "Ball.h"
//#include <chrono>
//#include <thread>



/*
things to consider :
	- i might want to change how i store pointers to circles and balls in the renderer (so that they are not separate)
	!!!- i would like to dig deeper into "how do i increase fps here?", most likely changing the way i draw frames AND/OR make them (think double buffering)
	- Ball::Bounce() is not looking good, im pretty sure i can come up with a pretty solution if i put some thoughts into that
	- adding a scale value for rendering might be a good idea - if i want more objects to display preserving relative distance between them, multiplying x and y coordinates in the MakeFrame() loop

	!!! ok, so i managed to improve frame output significantly by decreasing cout calls, and theres still room for improvement - i can combine all lines into one string and output that way, which would result in only one cout per frame
	1 Additionally, i encountered a strange behavior in ball.bounce(). sometimes it goes out of vector borders, seems to be when a collision happens?? this does not seem to happen with less balls in the vector
	2 another issue is that after a ball-ball collision one ball seems to "disappear", in reality it seems like they are at coordinates far beyond the screen, while the other one is pinned at the collision coordinates

P.S: for the full list address the cereal box lists
*/



int main()
{
	Circle* circle1 = new Circle();
	AddCircle(circle1);

	Circle* circle2 = new Circle(90, 90, 0, 30);
	AddCircle(circle2);
	
	Ball* ball2 = new Ball(30, 70, 14, 5.4, -3.7);
	AddBall(ball2);

	Ball* ball3 = new Ball(130, 130, 22, 1.4, 7.2);
	AddBall(ball3);

	Ball* ball4 = new Ball(50, 50, 7, 5.4, 3.7);
	//AddBall(ball4);

	Ball* ball5 = new Ball(130, 130, 4, -1.4, 7.2);
	//AddBall(ball5);

	while (true) //main loop - redraws frames
	{
		MakeFrame();
		DrawFrame();
		std::cout << ball2->cx << "\n" << ball2->cy << "\n";
	}

	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return 0;
}