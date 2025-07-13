#include <SFML\Graphics.hpp>
#pragma once

using namespace sf;

class Crosshair
{
public:
	Crosshair()
	{

	}
	~Crosshair() {}

	void Update(RenderWindow& window)
	{

	}

private:
	RectangleShape horizontal;
	RectangleShape vertical;
};
