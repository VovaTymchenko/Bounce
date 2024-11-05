#include <iostream>
#include "Renderer.h"
#include "Circle.h"
#include <chrono>
#include <thread>

int main()
{
	Circle circle1;
	AddCircle(circle1);
	
	circle1.cx = 70;
	AddCircle(circle1);

	Circle circle2(40, 40, 0, 30);
	AddCircle(circle2);
	
	//while (true) //main loop - redraws frames
	{
		MakeFrame();
		DrawFrame();
	}

	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return 0;
}