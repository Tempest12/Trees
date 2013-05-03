#ifndef _COLOUR4F_HPP
#define _COLOUR4F_HPP

class Colour4f
{
//Variables:
public:
	float red;
	float green;
	float blue;
	float alpha;

protected:
private:

//Functions
public:
	Colour4f();
	Colour4f(float grey);
	Colour4f(float red, float green, float blue);
	Colour4f(float red, float green, float blue, float alpha);

	~Colour4f();


	void print(void);
    void set(float red, float green, float blue, float alpha);
    void set(Colour4f& that);

protected:
private:
};

#endif
