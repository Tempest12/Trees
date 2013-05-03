#include <iostream>

#include "Colour4f.hpp"

Colour4f::Colour4f() : Colour4f(0.0f)
{
}

Colour4f::Colour4f(float grey) : Colour4f(grey, grey, grey)
{
}

Colour4f::Colour4f(float red, float green, float blue) : Colour4f(red, green, blue, 1.0f)
{
}

//The constructor that actually does stuff.
Colour4f::Colour4f(float red, float green, float blue, float alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha;
}

Colour4f::~Colour4f()
{
	return;
}

void Colour4f::print(void)
{
	std::cout << "R: " << this->red << " G: " << this->green << " B: " << this->blue << std::endl;
}

void Colour4f::set(float red, float green, float blue, float alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha;	
}

void Colour4f::set(Colour4f& that)
{
	this->red = that.red;
	this->green = that.green;
	this->blue = that.blue;
	this->alpha = that.alpha;
}
