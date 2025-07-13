#include "Game.h"

Game::Game() : 
	state(0),
	scoreSystem(&ui),
	ui(scoreSystem.GetScore(), &state),
	starfield(0.1f),
	obstacleSpawner(0.2f)
{
	player.SetPosition({ 1280.0f, 800.0f });
}

void Game::Update(RenderWindow& window, float deltaTime) 
{
	starfield.Update(window, deltaTime);
	particleSystem.Update(window, deltaTime);
	obstaclePool.Move(deltaTime); 
	obstaclePool.Draw(window); 

	switch (state) 
	{  
	case 0: 
		ui.StartScreen(window);  
		break;
	case 1: 
		obstacleSpawner.Do(&obstaclePool.obstacles, deltaTime);  
		player.UpdateGun(particleSystem, obstaclePool, window, deltaTime);  
		obstaclePool.ObstacleInteraction(deltaTime, particleSystem, scoreSystem); 

		if (player.isDead()) 
			state = 2; 

		ui.PlayScreen(window);  
		break;
	case 2: 
		ui.GameOverScreen(window);  
		break;
	case 3: // reset state 
		player.SetHealth(player.GetMaxHealth()); 
		player.SetPosition({ 1280.0f, 800.0f });
		player.SetDead(); 
		obstaclePool.playerObstacles.push_back(&player); 
		scoreSystem.SetHighscore(scoreSystem.GetScore()); 
		scoreSystem.SetScore(0);
		state = 1;
		break;
	}
}
