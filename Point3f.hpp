#ifndef _POINT_HPP
#define _POINT_HPP

#include "Vector3f.hpp"

class Point3f
{

//Variables
public:
    Vector3f position;

protected:

private:


//Functions

public:

    Point3f();
    Point3f(Vector3f& position);
    Point3f(Vector3f* position);

protected:

private:

};


namespace Point3fUtil
{


}

#endif
