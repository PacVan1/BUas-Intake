#include <SFML\Graphics.hpp>
#include "Star.h"
#include <vector>
#include <iterator>
#pragma once

using namespace std;
using namespace sf;

class Starfield
{
public: 
	Starfield(float rate);
	~Starfield() {}

	void Update(RenderWindow& window, float deltaTime);

private:
	void CreateStar(float velocity, float radius, int brightness); 

private:
	vector<Star*> starfield;

	float currentTime;
	float rate;
};

