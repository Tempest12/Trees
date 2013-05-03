#include <GL/glut.h>
#include <iostream>
#include <math.h>

#include "AttractionPoint.hpp"
#include "Config.hpp"
#include "Node.hpp"


Node::Node(void) : Point3f()
{
	this->parent = NULL;
	this->radius = Config::convertSettingToFloat("tree", "starting_radius");

	this->children = std::vector<Node*>();
	this->attractingPoints = std::vector<AttractionPoint*>();

	this->branchLength = Config::convertSettingToFloat("tree", "branch_length");
	this->supporting = 1;
}

Node::Node(Vector3f* position, Node* parent) : Point3f(position)
{
	this->parent = parent;
    this->radius = Config::convertSettingToFloat("tree", "starting_radius");

	this->children = std::vector<Node*>();
	this->attractingPoints = std::vector<AttractionPoint*>();

	this->branchLength = Config::convertSettingToFloat("tree", "branch_length");
	this->supporting = 1;

	if(parent == NULL)
	{
	}
	else
	{
		Vector3f between = Vector3f(this->position);
		between.subtract(&(parent->position));

		float length = between.magnitude();
		this->angle = 57.2957795*acos(between.z / length);

        std::cout << angle << std::endl;

		if (between.z < 0.0 )
	    {
	    	this->angle *= -1;
	    }


		this->rX = -between.y * between.z;
		this->rY = between.x * between.z;
	}
}

Node::~Node(void)
{	
}

void Node::addAttractionPoint(AttractionPoint* point)
{
	attractingPoints.push_back(point);
}

void Node::draw(GLUquadricObj* quadric)
{
	glPushMatrix();

		//Brown
	    //rgb 0.627451 0.321569 0.176471
        
        
        glTranslatef(this->parent->position.x, this->parent->position.y, this->parent->position.z);
        glRotatef(this->angle, this->rX, this->rY, 0.0);
		gluCylinder(quadric, this->parent->supporting  * this->radius, this->supporting * this->radius, this->branchLength, 7, 7);

	glPopMatrix();
}

Node* Node::grow(void)
{
    if(attractingPoints.size() == (unsigned int)0)
	{
		return NULL;
	}
	else
	{
		Vector3f temp = Vector3f();
		Vector3f direction = Vector3f();

        //std::cout << "Size: " << attractingPoints.size() << std::endl;

        for(int index = 0; (unsigned int)index < attractingPoints.size(); index++)
		{
            //std::cout << "Index " << index << ": " << attractingPoints[index] << std::endl;
			direction.set(&(attractingPoints[index]->position));
			direction.subtract(&(this->position));
            temp.add(direction);
		}

        temp.divideByScalar(attractingPoints.size());
        temp.normalize();
        temp.scale(this->branchLength);
        temp.add(this->position);

		Node* newNode = new Node(&temp, this);

        children.push_back(newNode);
        

        if(children.size() > 1)
        {
        	supporting++;
            this->runDown();
        }

        //std::cout << (*newNode) << std::endl;

        attractingPoints.clear();

        return newNode;
	}
}

void Node::runDown(void)
{
	Node* next = this->parent;

	while(next != NULL)
	{
		if(this->supporting > next->supporting)
		{
			next->supporting = this->supporting;
			next = next->parent;
		}
		else
		{
			return;
		}
	}
}
