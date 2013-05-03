#ifndef ATTRACTIONPOINT_HPP
#define ATTRACTIONPOINT_HPP

#include <vector>

#include "Colour4f.hpp"
#include "Point3f.hpp"

class Node;

class AttractionPoint : public Point3f
{
//Variables
public:
	float killDistance;
	float attractionDistance;

	Colour4f usedColour;
	Colour4f unusedColour;

    Colour4f colour;

protected:
private:


//Functions
public:
	AttractionPoint();
	AttractionPoint(Vector3f& position);
	AttractionPoint(Vector3f* position);

	~AttractionPoint();

	bool die(std::vector<Node*>& nodeList);
	void findClosestNode(std::vector<Node*>& nodeList);

protected:
private:

};

namespace AttractionPointUtil
{


}

#endif // ATTRACTIONPOINT_HPP
