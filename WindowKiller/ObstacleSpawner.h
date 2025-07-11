#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include <list>
#include <iterator>
#include <cmath>
#pragma once

using namespace sf;

class ObstacleSpawner
{
public:
	ObstacleSpawner(float spawnRate);
	~ObstacleSpawner();
	void Do(list<Obstacle*>* obstacles, float deltaTime);

private:
	vector<Obstacle> obsTypes;
	float spawnRate; // in seconds
	float currentTime;
};

