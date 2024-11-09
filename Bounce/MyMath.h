#pragma once

struct vector2d
{
	float x, y;
	vector2d();
	vector2d(float x, float y);
	vector2d Normalize(); //returns a new vector which is this normalized
	vector2d MultScalar(float scalar); //returns a new vector which is this multiplied by scalar
	float DotProduct(vector2d vector2); //return dot product of this and another vector
};
float FindLength(float x1, float y1, float x2, float y2); //find distance between two coordinates
float FindLength(float x, float y); //find length of a vector