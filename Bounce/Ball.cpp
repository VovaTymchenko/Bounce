#include "Ball.h"

Ball::Ball()
{
	cx = 0;
	cy = 0;
	r = 0;
	thickness = 4;
	spdX = 0;
	spdY = 0;
}

Ball::Ball(float cx, float cy, float thickness, float spdX, float spdY)
{
	this->cx = cx;
	this->cy = cy;
	r = 0;
	this->thickness = thickness;
	this->spdX = spdX;
	this->spdY = spdY;
}

void Ball::Move() //change coordinates based on the ball speed
{
	cx += spdX;
	cy += spdY;
}

void Ball::Bounce(std::vector<Circle*> circles, std::vector<Ball*> balls, int i, float symbMod) //handling collisions
{
	for (int k = 0; k < circles.size(); k++) //checking collision with circles
	{
		float distance = FindLength(circles[k]->cx, circles[k]->cy, balls[i]->cx, balls[i]->cy);
		if (abs(distance - circles[k]->r - balls[i]->r) <= circles[k]->thickness + balls[i]->thickness) //radius is supposed to always be 0, but ill leave it in the formula just in case
		{ 
			vector2d normal(balls[i]->cx - circles[k]->cx, balls[i]->cy - circles[k]->cy);
			Normalize(normal);

			vector2d velocity(spdX, spdY);
			AddVector(velocity, MultScalar(normal, (-2 * DotProduct(velocity, normal))));
			//v new = v - 2(v . n) * n
			//^^^velocity - 2 * projection of velocity on normal^^^




			spdX = -spdX; spdY = -spdY;
		}
	}

	for (int k = 0; k < balls.size(); k++) //checking collision with balls
	{
		if (k == i) continue;

		float distance = FindLength(balls[k]->cx, balls[k]->cy, balls[i]->cx, balls[i]->cy);
		if (abs(distance - balls[k]->r - balls[i]->r) <= balls[k]->thickness + balls[i]->thickness) //radius is supposed to always be 0, but ill leave it in the formula just in case
		{
			spdX = -spdX; spdY = -spdY;
		}
	}
}

void Ball::Split() //TBD
{
	//sounds fun, but i gotta do the main batch first
}