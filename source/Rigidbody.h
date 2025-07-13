#include <SFML\Graphics.hpp> 
#pragma once

using namespace sf;

class Rigidbody
{
public:
	Rigidbody();
	Rigidbody(Vector2f velocity, float friction, int mass);
	Rigidbody(Vector2f* position, Vector2f velocity, float friction, int mass);
	~Rigidbody() {}

	Vector2f GetPosition() { return *position_p; }
	Vector2f GetVelocity() { return velocity; }
	int GetMass() { return mass; }
	float GetFriction() { return friction; }
	void SetPosition(Vector2f position) { *position_p = position; }
	void SetVelocity(Vector2f velocity) { this->velocity = velocity; }
	void Accelarate(Vector2f accelaration) { velocity += accelaration; }
	void Move();

public: 
	Vector2f velocity;
	Vector2f accelaration;
	Vector2f* position_p;

private:
	float friction;
	int mass;
};

