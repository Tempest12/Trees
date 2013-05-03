#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>
#include <random>

#include "Colour4f.hpp"
#include "Config.hpp"
#include "Envelope.hpp"
#include "glpanel.h"
#include "MathLib.hpp"
#include "Vector3f.hpp"

//Author Shane del Solar

Envelope::Envelope(void)
{
	this->rings = std::vector<float>();
	this->ringHeight = 0.0f;
	this->baseHeight = 0.0f;
	this->colour = Colour4f();
}

Envelope::Envelope(int numOfRings)
{
	this->rings = std::vector<float>(numOfRings);
	this->ringHeight = 0.0f;
	this->baseHeight = 0.0f;
	this->colour = Colour4f();
}

Envelope::Envelope(std::string& path)
{
	this->fileName.assign(path);
	this->load(path);

    this->colour = Colour4f(Config::convertSettingToFloat("colours", "envelope_red"),
                            Config::convertSettingToFloat("colours", "envelope_green"),
                            Config::convertSettingToFloat("colours", "envelope_blue"),
                            Config::convertSettingToFloat("colours", "envelope_alpha"));
}

Envelope::~Envelope(void)
{	
}

void Envelope::draw(void)
{	
	glPushMatrix();

	//glLoadIdentity();

	glTranslatef(0.0, this->baseHeight, 0.0);

	//std::cout << "Hey" << std::endl;

    //this->colour.print();

	glColor4f(this->colour.red, this->colour.green, this->colour.blue, this->colour.alpha);

	for(std::vector<float>::iterator iterator = this->rings.begin(); iterator != this->rings.end(); iterator++)
	{
        //std::cout << *iterator << std::endl;
        glPanelUtil::drawCircle(*iterator, 25);
		glTranslatef(0.0f, this->ringHeight, 0.0f);
	}

	glPopMatrix();
}

void Envelope::getSpawnPosition(Vector3f* position, std::minstd_rand0* random)
{
    float mid = (float)(*random)()/(float)RAND_MAX;
	int ring = (*random)() % (this->rings.size() - 1) + 1;
    float diff = 1.0f - mid;

    float maxLength = mid * this->rings[ring] + diff * this->rings[ring - 1];
    float angle = (*random)() % 360;
    angle = MathLib::toRadians(angle);

    float length = (float)(*random)()/(float)RAND_MAX;

	position->x = cosf(angle) * (maxLength * length);
	position->y = ((ring - 1) * this->ringHeight) + (mid * ringHeight) + baseHeight;
    position->z = sinf(angle) * (maxLength * length);
}

bool Envelope::load(std::string& path)
{
	this->fileName.assign(path);

	this->rings = std::vector<float>();
	std::fstream file;

	file.open(path, std::fstream::in);

	if(file.is_open())
	{
		std::string line;

		this->rings = std::vector<float>();

		std::getline(file, line);
		this->baseHeight = std::stof(line);

		std::getline(file, line);
		this->ringHeight = std::stof(line);

		while(file.good())
		{
			std::getline(file, line);
            //std::cout << line << std::endl;

			this->rings.push_back(std::stof(line));

		}
	}
	else
	{
		std::cout << "Envelope file not found." << std::endl;
		return false;
	}

	std::cout << "File: " << path << " loaded successfully." << std::endl;

	return true;
}

void Envelope::save(void)
{
	std::fstream file;
	
	if(this->fileName.length() == 0)
	{
		this->fileName.assign("Envelope.txt");		
	}

    file.open(this->fileName, std::fstream::out | std::fstream::trunc);

	file << this->rings.size() << std::endl;
	file << this->ringHeight << std::endl;

	for(int index = 0; index < (int)this->rings.size(); index++)
	{
		file << this->rings[index] << std::endl;
    }

	file.close();
}
