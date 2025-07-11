#include <SFML\Graphics.hpp>
#pragma once

using namespace sf;

class Star
{
public:
	Star(float y, float velocity, float radius, int brightness);
	~Star() {}

	float GetX() { return shape.getPosition().x; }
	void Move();
	void Draw(RenderWindow& window);

private:
	CircleShape shape;
	float velocity;
};

