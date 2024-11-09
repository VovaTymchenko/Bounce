#include <iostream>
#include "MyMath.h"

float FindDistance(float x1, float y1, float x2, float y2) //find distance between two coordinates - ALWAYS POSITIVE
{
	return abs(sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}