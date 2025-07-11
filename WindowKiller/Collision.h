#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#pragma once

class Collision
{
public: 
	bool CollisionDetected(Obstacle& obs1, Obstacle& obs2);
	void CollisionResponse(Obstacle& obs1, Obstacle& obs2);
};

