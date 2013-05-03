#ifndef _MATHLIB_HPP
#define _MATHLIB_HPP

//#define __USE_GNU
#include <math.h>

namespace MathLib
{	
    extern const float PI;
	
	float toRadians(float degrees);
	float toDegrees(float radians);
}

#endif
