#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Renderer.h"
#include "Circle.h"

using namespace std;

const char symb[6] = { ' ', '.', ':' , ';' , '+' , '#' }; //console gradient for overlapping objects

const float symbH = 10, symbW = 5; //console symbol pixel size
const int frameH = 80, frameW = 160; //draw surface dimensions - 1
int frame[frameH + 1][frameW + 1]; //frame "pixel" data

std::vector<Circle*> circles; //array of the objects to be displayed

void DrawFrame()
{
	system("cls");

	for (int i = 0; i < frameH; i++)
	{
		for (int j = 0; j < frameW; j++)
		{
			cout << symb[min(frame[i][j], 5)];
		}
		cout << "\n";
	}
	cout << circles[0] << endl;
	cout << circles[1] << endl;
	cout << circles[2] << endl;
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
				if (abs(sqrt(pow((i * (symbH / symbW) - circles[k]->cy), 2) + pow((j - circles[k]->cx), 2)) - circles[k]->r) <= circles[k]->thickness) frame[i][j] = frame[i][j] + 1;
			}
		}
	}
}

void AddCircle(Circle pCircle)
{
	circles.push_back(&pCircle);
}

void RemoveCircle(int index)
{ 
	circles.erase(circles.begin() + index);
}