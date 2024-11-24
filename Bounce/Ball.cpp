#include <iostream>
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

void Ball::Bounce(const std::vector<Circle*>& circles, const std::vector<Ball*>& balls, int i, float symbMod, const int frameH, const int frameW) //handling collisions
{
	//left & right bounce
	if (balls[i]->cx - balls[i]->r - balls[i]->thickness <= 0) //left
	{
		balls[i]->cx += 2 * ((balls[i]->r + balls[i]->thickness) - balls[i]->cx); //turns overshoot into position after precise bounce
		balls[i]->spdX = -spdX;
	}
	if (balls[i]->cx + balls[i]->r + balls[i]->thickness >= frameW) //right
	{
		balls[i]->cx -= 2 * ((balls[i]->r + balls[i]->thickness) - frameW + balls[i]->cx); //turns overshoot into position after precise bounce
		balls[i]->spdX = -spdX;
	}

	//top & bottom bounce
	if (balls[i]->cy - balls[i]->r - balls[i]->thickness <= 0) //bottom
	{
		balls[i]->cy += 2 * ((balls[i]->r + balls[i]->thickness) - balls[i]->cy); //turns overshoot into position after precise bounce
		balls[i]->spdY = -spdY;
	}
	if (balls[i]->cy + balls[i]->r + balls[i]->thickness >= frameH * symbMod) //top
	{
		balls[i]->cy -= 2 * ((balls[i]->r + balls[i]->thickness) - (frameH * symbMod) + balls[i]->cy); //turns overshoot into position after precise bounce
		balls[i]->spdY = -spdY;
	}

	for (int k = 0; k < circles.size(); k++) //checking collision with circles
	{
		float distance = FindLength(circles[k]->cx, circles[k]->cy, balls[i]->cx, balls[i]->cy);
		if (abs(distance - circles[k]->r - balls[i]->r) <= circles[k]->thickness + balls[i]->thickness) //radius is supposed to always be 0, but ill leave it in the formula just in case
		{
			vector2d normal(balls[i]->cx - circles[k]->cx, balls[i]->cy - circles[k]->cy);
			normal = Normalize(normal);

			vector2d velocity(spdX, spdY);
			vector2d newVelocity = AddVector(velocity, MultScalar(normal, (-2 * DotProduct(velocity, normal))));
			//v new = v - 2(v . n) * n
			//^^^velocity - 2 * projection of velocity on normal^^^

			spdX = newVelocity.x;
			spdY = newVelocity.y;

			break;
		}
	}

	for (int k = 0; k < balls.size(); k++) //checking collision with balls
	{
		if (k == i) continue;

		float distance = FindLength(balls[k]->cx, balls[k]->cy, balls[i]->cx, balls[i]->cy);
		if (abs(distance - balls[k]->r - balls[i]->r) <= balls[k]->thickness + balls[i]->thickness) //radius is supposed to always be 0, but ill leave it in the formula just in case
		{
			balls[k]->cx -= spdX;
			balls[k]->cy -= spdY;
			//this might look rather complicated, but all this is a result of figuring out a location where the colliding objects should have met between the "pre-collision" -> "collision" frames
			//to work out the "time" multiplier for the speeds of the objects, this formula was used:
			// 
			//||(c1,0 + t * v1) - (c2,0 + t * v2)|| = r1 + r2
			// 
			//where c1,0 and c2,0 are objects' "pre-collision" frame location vectors, v1 and v2 are their speed vectors, r1 and r2 are radiuses, and the "time" t is the speed multiplier we are trying to find
			//after doing some maths to find the formula for the "time" t, we get a quadratic equation:
			float t, A, B, C; //quadratic equation parameters
			vector2d deltaC0 = AddVector(vector2d(balls[i]->cx, balls[i]->cy), vector2d(-balls[k]->cx, -balls[k]->cy));
			vector2d deltaV = AddVector(vector2d(balls[i]->spdX, balls[i]->spdY), vector2d(-balls[k]->spdX, -balls[k]->spdY));
			A = pow(FindLength(deltaV), 2); //square the length of delta v
			B = 2 * DotProduct(deltaC0, deltaV); //2 * (delta c0 dot delta v)
			C = pow(FindLength(deltaC0), 2) - pow((balls[i]->r + balls[i]->thickness + balls[k]->r + balls[k]->thickness), 2); //square the length of delta c0 - square the sum of r
			t = (-B + sqrt(pow(B, 2) - 4 * A * C)) / (2 * A); //the quadratic equation

			vector2d normal((balls[i]->cx + balls[i]->spdX * t) - (balls[k]->cx + balls[k]->spdX * t), (balls[i]->cy + balls[i]->spdY * t) - (balls[k]->cy + balls[k]->spdY * t));
			normal = Normalize(normal);

			vector2d velocity(spdX, spdY);
			vector2d newVelocity = AddVector(velocity, MultScalar(normal, (-2 * DotProduct(velocity, normal))));
			//v new = v - 2(v . n) * n
			//^^^velocity - 2 * projection of velocity on normal^^^

			spdX = newVelocity.x;
			spdY = newVelocity.y;

			break;
		}
	}
}

void Ball::Split() //TBD
{
	//sounds fun, but i gotta do the main batch first
}