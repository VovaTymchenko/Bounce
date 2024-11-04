#include "Circle.h"

Circle::Circle()
{
	cx = 0;
	cy = 0;
	r = 10;
	thickness = 1;
};

Circle::Circle(float cx, float cy, float r, float thickness)
{
	this->cx = cx;
	this->cy = cy;
	this->r = r;
	this->thickness = thickness;
};