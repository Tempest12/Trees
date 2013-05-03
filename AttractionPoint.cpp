#include <iostream>
#include <vector>

#include "AttractionPoint.hpp"
#include "Colour4f.hpp"
#include "Config.hpp"
#include "Node.hpp"
#include "Vector3f.hpp"


AttractionPoint::AttractionPoint() : Point3f()
{
    this->killDistance = Config::convertSettingToFloat("tree", "kill_distance");
    this->attractionDistance = Config::convertSettingToFloat("tree", "attraction_distance");

    this->unusedColour = Colour4f(Config::convertSettingToFloat("colours", "attraction_point_unused_red"),
    						      Config::convertSettingToFloat("colours", "attraction_point_unused_green"),
    						      Config::convertSettingToFloat("colours", "attraction_point_unused_blue"),
    							  Config::convertSettingToFloat("colours", "attraction_point_unused_alpha"));

    this->usedColour = Colour4f(Config::convertSettingToFloat("colours", "attraction_point_used_red"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_green"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_blue"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_alpha"));

    this->colour.set(this->unusedColour);
}

AttractionPoint::AttractionPoint(Vector3f& that) : Point3f(that)
{
    this->killDistance = Config::convertSettingToFloat("tree", "kill_distance");
    this->attractionDistance = Config::convertSettingToFloat("tree", "attraction_distance");

    this->unusedColour = Colour4f(Config::convertSettingToFloat("colours", "attraction_point_unused_red"),
    						      Config::convertSettingToFloat("colours", "attraction_point_unused_green"),
    						      Config::convertSettingToFloat("colours", "attraction_point_unused_blue"),
    							  Config::convertSettingToFloat("colours", "attraction_point_unused_alpha"));

    this->usedColour = Colour4f(Config::convertSettingToFloat("colours", "attraction_point_used_red"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_green"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_blue"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_alpha"));

    this->colour.set(this->unusedColour);
}

AttractionPoint::AttractionPoint(Vector3f* that) : Point3f(that)
{
    this->killDistance = Config::convertSettingToFloat("tree", "kill_distance");
    this->attractionDistance = Config::convertSettingToFloat("tree", "attraction_distance");

    this->unusedColour = Colour4f(Config::convertSettingToFloat("colours", "attraction_point_unused_red"),
    						      Config::convertSettingToFloat("colours", "attraction_point_unused_green"),
    						      Config::convertSettingToFloat("colours", "attraction_point_unused_blue"),
    							  Config::convertSettingToFloat("colours", "attraction_point_unused_alpha"));

    this->usedColour = Colour4f(Config::convertSettingToFloat("colours", "attraction_point_used_red"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_green"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_blue"),
    							Config::convertSettingToFloat("colours", "attraction_point_used_alpha"));

    this->colour.set(this->unusedColour);
}

bool AttractionPoint::die(std::vector<Node*>& nodeList)
{
	for(unsigned int index = 0; index < nodeList.size(); index++)
	{
		if(Vector3fUtil::distance(&(this->position), &(nodeList[index]->position)) <= this->killDistance)
		{
			//std::cout << "Killed" << std::endl;
			return true;
		}
	}

	return false;
}

void AttractionPoint::findClosestNode(std::vector<Node*>& nodeList)
{
	if(nodeList.size() == 0)
	{
		return;
	}

	Node* closestNode = nodeList[0];
    float distance = Vector3fUtil::distance(&(this->position), &(nodeList[0]->position));

	float temp = 0.0f;

    for(int index = 1; (unsigned int)index < nodeList.size(); index++)
	{
		temp = Vector3fUtil::distance(&(this->position), &(nodeList[index]->position));

		if(distance > temp)
		{
			distance = temp;
			closestNode = nodeList[index];
		}
	}

    if(distance <= this->attractionDistance)
	{
		this->colour.set(this->usedColour);
	    closestNode->addAttractionPoint(this);
	}
	else
	{
		this->colour.set(this->unusedColour);
	}
}

AttractionPoint::~AttractionPoint()
{
}
