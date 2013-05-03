#ifndef _TREE_HPP
#define _TREE_HPP


#include <GL/glut.h>
#include <random>
#include <vector>

#include "AttractionPoint.hpp"
#include "Envelope.hpp"
#include "Node.hpp"

class Tree
{
//Variables
public:
	bool drawEnvelope;
	Envelope envelope;
	
	bool drawAttractionPoints;
	std::vector<AttractionPoint> attractionPoints;
	int attractionPointsCount;

	std::minstd_rand0 random;

	Node* root;

	std::vector<Node*> nodes;

	GLUquadricObj* quadric;

protected:
private:


//Functions
public:
	Tree();

	void draw(void);
    
    void reset(void);

    void spawnNewPoints(void);

    void spawnAttractionPoints(void);
    bool update(void);

protected:
private:
};

namespace TreeUtil
{

}

#endif
