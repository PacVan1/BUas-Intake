#include <SFML\Graphics.hpp>
#pragma once

using namespace std;
using namespace sf;

class Mineral
{
public: 
	Mineral(Vector2f position, int minerals) :
		position(position),
		minerals(minerals){}
	~Mineral() {}

private:
	Vector2f position;
	int minerals;
};

