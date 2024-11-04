#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Renderer.h"
#include "Circle.h"

using namespace std;

const char symb[6] = { ' ', '.', ':' , ';' , '+' , '#' }; //console gradient for overlapping objects

const int symbH = 5, symbW = 2; //console symbol pixel size
const int frameH = 63, frameW = 127; //draw surface dimensions - 1
int frame[frameH + 1][frameW + 1]; //frame "pixel" data

std::vector<Circle> circles; //array of the objects to be displayed

void DrawFrame()
{
	system("cls");

	for (int i = 0; i < frameH; i++)
	{
		for (int j = 0; j < frameW; j++)
		{
			cout << symb[frame[i][j]];
		}
		cout << "\n";
	}
}

void MakeFrame()
{
	for (int i = 0; i < frameH; i++)
	{
		for (int j = 0; j < frameW; j++)
		{
			frame[i][j] = 0;
			for (int k = 0; k < circles.size(); k++)
			{
				if (abs(sqrt(pow((i * (symbH / symbW) - circles[k].cx), 2) + pow((j - circles[k].cy), 2)) - circles[k].r) <= circles[k].thickness) frame[i][j] = frame[i][j] + 1;
			}
		}
	}
}
//
//void AddCircle(Circle pCircle)
//{
//	circles.push_back(pCircle);
//}
//
//void RemoveCircle(Circle pCircle)
//{
//	circles.erase(std::remove(circles.begin(), circles.end(), pCircle), circles.end());
//}