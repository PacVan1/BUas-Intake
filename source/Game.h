#include <SFML\Graphics.hpp>
#include "UI.h"
#include "Starfield.h"
#include "ObstacleSpawner.h"
#include "ObstaclePool.h"
#include "ParticleSystem.h"
#include "ScoreSystem.h"
#include "Player.h"
#pragma once

using namespace std;
using namespace sf;

class Game
{
public: 
	Game();
	~Game() {}
	void Update(RenderWindow& window, float deltaTime);
	void ChangeState(int state) { this->state = state; }

private: 
	UI ui;
	Starfield starfield;
	ObstacleSpawner obstacleSpawner;
	ObstaclePool obstaclePool; 
	ParticleSystem particleSystem;
	ScoreSystem scoreSystem;
	Player player;

	int state;
};

