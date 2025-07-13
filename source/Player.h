#include <SFML\Graphics.hpp>
#include "Obstacle.h"
#include "Gun.h"
#include "Bar.h"
#pragma once

using namespace sf;

class Player : public Obstacle
{
public:
	Player();
	Player(Vector2f position, Color color, int radius, bool friction, int damage, int health, int mass);
	~Player() {}

	void Move();

	void UpdateGun(ParticleSystem& particleSystem, ObstaclePool& obstaclePool, RenderWindow& window, float deltaTime);
	void Draw(RenderWindow& window); 

private:
	Gun gun;
	Bar healthbar;
};

