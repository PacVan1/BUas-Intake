#include <SFML\Graphics.hpp>
#include "CircleCollider.h"
#include "Rigidbody.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include <cmath>
#pragma once

using namespace std;
using namespace sf; 

class Obstacle
{
public:
	Obstacle(Obstacle& obstacle, Vector2f position);
	Obstacle(Vector2f position, Color color, int radius, float friction, int damage, int health, int mass);
	~Obstacle() {}

	CircleShape* GetShapeP() { return &shape; }
	CircleShape GetShape() { return shape; }
	CircleCollider* GetColliderP() { return &collider; }	
	CircleCollider GetCollider() { return collider; }
	Rigidbody* GetRigidbodyP() { return &rigidbody; }
	Rigidbody GetRigidbody() { return rigidbody; }
	Vector2f* GetPositionP() { return &position; }
	Vector2f GetVelocity() { return rigidbody.velocity; }
	Vector2f GetPosition() { return position; }
	Color GetColor() { return shape.getOutlineColor(); }
	float GetRadius() { return shape.getRadius(); }
	int GetDamage() { return damage; }
	int GetHealth() { return health; }
	int GetMaxHealth() { return maxHealth; }
	bool isDead() { return dead; }

	Particle CreateParticle(); 
	void GetHit(ParticleSystem& particleSystem, int damage);
	virtual void Move();
	void SetPosition(Vector2f position) { this->position = position; }
	void SetHealth(int health) { this->health = health; }
	void SetDead() { dead = false; }
	void DecreaseHealth(int damage);

	virtual void Update();
	virtual void Draw(RenderWindow& window);

public:
	Rigidbody rigidbody;
	CircleCollider collider;
	CircleShape shape;

protected:
	Vector2f position;

	int damage;
	int health;
	int maxHealth;
	bool dead;
};

