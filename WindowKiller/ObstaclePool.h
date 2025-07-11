#include <SFML\Graphics.hpp>
#include "Obstacle.h"
#include "Collision.h"
#include "ScoreSystem.h"
#include <list> 
#include <iterator>
#pragma once

using namespace std; 
using namespace sf;

class ObstaclePool
{
public:
	ObstaclePool() {}
	~ObstaclePool() {}

	void ObstacleInteraction(float deltaTime, ParticleSystem& particleSystem, ScoreSystem& ui);
	void Move(float deltaTime);
	void Draw(RenderWindow& window);

public:
	list<Obstacle*> obstacles; 
	list<Obstacle*> playerObstacles; 

private:
	Collision collision;
};

