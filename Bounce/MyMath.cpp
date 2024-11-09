#include <iostream>
#include "MyMath.h"

struct vector2d
{
	float x, y;
	vector2d()
	{
		x = 0;
		y = 0;
	}
	vector2d(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	vector2d MultScalar(float scalar) //returns a new vector which is this multiplied by scalar
	{
		vector2d newVec2d(this->x, this->y);
		newVec2d.x *= scalar;
		newVec2d.y *= scalar;
		return newVec2d;
	}
	float DotProduct(vector2d vector2) //return dot product of this and another vector
	{
		return (this->x * vector2.x + this->y * vector2.y);
	}
};

float FindLength(float x1, float y1, float x2, float y2) //find distance between two coordinates
{
	return abs(sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

float FindLength(float x, float y) //find length of a vector
{
	return abs(sqrt(pow(x, 2) + pow(y, 2)));
}