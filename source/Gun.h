#include <SFML\Graphics.hpp>
#include "Obstacle.h"
#include "ParticleSystem.h"
#include "ObstaclePool.h"
#include <list>
#pragma once

using namespace std;
using namespace sf;

class Gun
{
public:
	Gun(Obstacle* owner, float bulletSpeed, float fireRate);
	~Gun();

	Vector2f GetDirection() { return direction; }
	Vector2f GetPosition() { return barrel.getPosition(); }
	void SetDirection() { this->direction = direction; }
	void SetPosition(Vector2f position) { barrel.setPosition(position); }
	void Reload(float deltaTime);
	void Fire(ParticleSystem& particleSystem, ObstaclePool& obstaclePool);
	void Aim(Vector2i target);
	void Knockback();
	void Update(RenderWindow& window, float deltaTime);
	void Draw(RenderWindow& window);

private:
	Obstacle* owner;
	Vector2f* position;
	Vector2f direction;

	RectangleShape barrel;
	Obstacle projectile;

	float bulletSpeed;
	float fireRate;
	float currentTime;
	bool canFire;
};

