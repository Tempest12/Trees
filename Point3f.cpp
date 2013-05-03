#include "Point3f.hpp"

Point3f::Point3f()
{
    this->position = Vector3f();
}

Point3f::Point3f(Vector3f &position)
{
    this->position = Vector3f(position);
}

Point3f::Point3f(Vector3f* position)
{
	this->position = Vector3f(position);
}