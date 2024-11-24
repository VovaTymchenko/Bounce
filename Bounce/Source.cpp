#include <iostream>
#include "Renderer.h"
#include "Circle.h"
#include "Ball.h"
//#include <chrono>
//#include <thread>



/*
things to consider :
	- sometimes Bounce() function might produce unexpected results due to the nature of computing itself. Because all operations are done in a sequence, having balls with higher speeds might result in "fake" bounces, that
		would not happen if all the balls were moving simultaneously (if after a frame update a single ball collides with two other objects, it is hard to tell which object it should have collided with first). To improve 
		situation, I can add a variable "precision", which would measure how many times should the scene update per frame. With this, each update would move balls by (spdX / precision, spdY / precision)*, preserving the 
		displacement of the balls between frames, while improving the precision of all collisions by fixing the order of bounces.
		
		WARNING: this will increase the complexity behind each frame from O(n) to O(n*precision). Since currently the bottleneck of console drawing framerate is output, low precision values should not cause problems, but
		as precision value gets bigger it might start increasing the time it takes to update each frame, potentionally dramatically reducing framerate.

		*in reality, their speed will be initially set to spdX / precision, and a loop in the main() will call MakeFrame() precision times, so it's not moving it by a fraction of its speed, but making its speed a fraction 
		and then moving normally "precision" times
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