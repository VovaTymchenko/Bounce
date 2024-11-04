#include <iostream>
#include "Renderer.h"
#include "Circle.h"
#include <chrono>
#include <thread>

int main()
{
	Circle circle1;

	//circle1.cx = 5;
	MakeFrame();
	DrawFrame();

	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return 0;
}