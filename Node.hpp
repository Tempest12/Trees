#ifndef _NODE_HPP
#define _NODE_HPP

#include <GL/glut.h>
#include <vector>
#include <iostream>

#include "Point3f.hpp"

class AttractionPoint;

class Node : public Point3f
{

//Variables	
public:
	Node* parent;
	float radius;
	float size;
	float branchLength;

	int supporting;

	std::vector<Node*> children;

	std::vector<AttractionPoint*> attractingPoints;

	float angle;
	float rX;
	float rY;

protected:
private:


//Functions
public:
	Node(void);
	Node(Vector3f* position, Node* parent);
	~Node(void);


	void addAttractionPoint(AttractionPoint* point);
	void draw(GLUquadricObj* quadric);
	Node* grow(void); 

	void runDown(void);

    /*inline std::ostream& operator <<(std::ostream& stream)
	{
		stream << "hey" << std::endl;

		return stream;
	}*/

	/*inline operator const char*()
	{
		std::ostringstream stream;

		stream << "Node. Position: " << this->position;

		return stream.str().c_str();
	}*/

protected:
private:
};

namespace NodeUtil
{


}

#endif
