#include <SFML\Graphics.hpp> 
#pragma once

using namespace sf;

class CircleCollider
{
public:
	CircleCollider();
	CircleCollider(int radius);
	CircleCollider(Vector2f* position, int radius);
	~CircleCollider() {}

	Vector2f GetPosition() { return *position_p; }	
	int GetRadius() { return radius; }
	void SetPosition(Vector2f position) { *position_p = position; }
	void SetRadius(int radius) { this->radius = radius; }

private:
	Vector2f* position_p;
	int radius;
};

