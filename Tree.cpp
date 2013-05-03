#include <GL/glut.h>

#include "AttractionPoint.hpp"
#include "Config.hpp"
#include "Tree.hpp"
#include "Vector3f.hpp"

Tree::Tree()
{
	this->attractionPoints = std::vector<AttractionPoint>();

	this->random = std::minstd_rand0();

	this->drawEnvelope = true;
	this->envelope = Envelope(Config::convertSettingToString("envelope", "file"));

	this->drawAttractionPoints = true;
    this->attractionPointsCount = Config::convertSettingToInt("tree", "points");
    this->spawnAttractionPoints();

    this->nodes = std::vector<Node*>();

    Vector3f temp = Vector3f();
    this->root = new Node(&temp, NULL);
    this->nodes.push_back(this->root);

    quadric = gluNewQuadric();
}



void Tree::draw(void)
{
	if(drawEnvelope)
	{
    	this->envelope.draw();
    }

    if(drawAttractionPoints)
    {
    	for(int index = 0; (unsigned int)index < attractionPoints.size(); index++)
    	{
	    	glPushMatrix();

                glColor4f(attractionPoints[index].colour.red,
                          attractionPoints[index].colour.green,
                          attractionPoints[index].colour.blue,
                          attractionPoints[index].colour.alpha);
                glTranslatef(attractionPoints[index].position.x, attractionPoints[index].position.y, attractionPoints[index].position.z);
	    		glutSolidSphere(0.05f, 5, 5);

	    	glPopMatrix();
    	}
    }

    glColor4f(0.45f, 0.30f, 0.10f, 1.0f);
    for(int index = 1; (unsigned int)index < nodes.size(); index++)
    {
    	nodes[index]->draw(this->quadric);
    }
}

void Tree::spawnAttractionPoints(void)
{
	Vector3f temp = Vector3f();

    for(int index = (int)this->attractionPoints.size(); index < this->attractionPointsCount; index++)
	{
		this->envelope.getSpawnPosition(&temp, &this->random);
		this->attractionPoints.push_back(AttractionPoint(temp));
	}
}

void Tree::spawnNewPoints(void)
{
	AttractionPoint temp = AttractionPoint();

	for(int index = 0; index < Config::convertSettingToInt("tree", "new_spawns"); index++)
	{
		this->envelope.getSpawnPosition(&(temp.position), &this->random);
		if(temp.die(this->nodes))
		{
			continue;
		}
		else
		{
			 this->attractionPoints.push_back(AttractionPoint(temp.position));
		}
	}
}

void Tree::clearAttractionPoints(void)
{
	attractionPoints.clear();
}

void Tree::update(void)
{
	this->spawnNewPoints();

	if(attractionPoints.size() == 0)
	{
		return;
	}

    for(int index = 0; (unsigned int)index < attractionPoints.size(); index++)
	{
		attractionPoints[index].findClosestNode(this->nodes);
	}

	Node* growth;
    int count = nodes.size();

	for(int index = 0; index < count; index++)
	{
		growth = nodes[index]->grow();

		if(growth == NULL)
		{

		}
		else
		{
			nodes.push_back(growth);
		}
	}

	unsigned int index = 0;

	while(index < attractionPoints.size())
	{
		if(attractionPoints[index].die(this->nodes))
		{
			attractionPoints.erase(attractionPoints.begin() + index);
		}
		else
		{
			index++;
		}
	}

    //std::cout << "Number of nodes is: " << nodes.size() << std::endl;
}
