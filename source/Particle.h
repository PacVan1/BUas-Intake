#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#pragma once

using namespace sf;

class Particle
{
public:
	Particle();
	Particle(Particle particle, Vector2f position, Vector2f velocity);
	Particle(Vector2f position, Vector2f velocity, Color color, int radius, int outlineThickness, bool friction);
	Particle(Color color, int radius, int outlineThickness, bool friction);
	~Particle() {}

	float GetRadius() { return shape.getRadius(); }
	CircleShape GetShape() { return shape; }
	bool FadeOut(unsigned int fadeOutSpeed);
	void Move() { rigidbody.Move(); };
	void Draw(RenderWindow& window);

public: 
	Rigidbody rigidbody;

private:
	Vector2f position;
	CircleShape shape;
};

