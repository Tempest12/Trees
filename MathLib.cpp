#include "MathLib.hpp"

const float MathLib::PI = (float)M_PI;

float MathLib::toRadians(float degrees)
{
	return degrees * 180.0f / PI;
}

float MathLib::toDegrees(float radians)
{
	return radians * PI / 180.0f;
}
