#ifndef _ENVELOPE_HPP
#define _ENVELOPE_HPP

#include <vector>
#include <string>
#include <QFileDialog>

#include "Vector3f.hpp"

class Colour4f;

namespace EnvelopeUtil
{

}

class Envelope
{
	//Variables
	public:
		std::vector<float> rings;
		float ringHeight;
		float baseHeight;
		Colour4f colour;

	protected:
	private:
		std::string fileName;

	//Functions
	public:
	
	Envelope(void);
	Envelope(int numOfRings);
    Envelope(std::string& file);

	~Envelope(void);

	void draw(void);
	void getSpawnPosition(Vector3f* position, std::minstd_rand0* random);

    bool load(std::string& path);
    void save(void);

	protected:
	private:
};

#endif
