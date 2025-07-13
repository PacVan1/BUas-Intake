#include "ObstacleSpawner.h"

ObstacleSpawner::ObstacleSpawner(float spawnRate) :
	currentTime(0.0f),
	spawnRate(spawnRate)
{
	obsTypes.push_back(Obstacle({ 0.0f, 0.0f }, Color::Green,   10, 0.0f, 1,  4, 1));
	obsTypes.push_back(Obstacle({ 0.0f, 0.0f }, Color::Cyan,    30, 0.0f, 3,  6, 3));
	obsTypes.push_back(Obstacle({ 0.0f, 0.0f }, Color::Yellow,  40, 0.0f, 4,  7, 4));
	obsTypes.push_back(Obstacle({ 0.0f, 0.0f }, Color::Magenta, 60, 0.0f, 6,  9, 6));
	obsTypes.push_back(Obstacle({ 0.0f, 0.0f }, Color::Red,     70, 0.0f, 7, 10, 7));
}

ObstacleSpawner::~ObstacleSpawner(){}

void ObstacleSpawner::Do(list<Obstacle*>* obstacles, float deltaTime)
{
	currentTime += deltaTime;

	if (currentTime > spawnRate)
	{
		currentTime -= spawnRate;

		int rindex = rand() % obsTypes.size();
		int side = rand() % 4;
		Vector2f obspos = Vector2f(0.0f, 0.0f);
		Vector2f obsvel = Vector2f(0.0f, 0.0f);

		switch (side)
		{
		case 0:
			obspos = Vector2f(2560 + obsTypes[rindex].GetRadius(), rand() % 1600 + 1);
			obsvel = Vector2f(0, rand() % 1600 + 1);
			break;
		case 1: 
			obspos = Vector2f(rand() % 2560 + 1, 1600 + obsTypes[rindex].GetRadius());
			obsvel = Vector2f(rand() % 2560 + 1, 0);
			break;
		case 2: 
			obspos = Vector2f(0 - obsTypes[rindex].GetRadius(), rand() % 1600 + 1);
			obsvel = Vector2f(2560, rand() % 1600 + 1);
			break;
		case 3: 
			obspos = Vector2f(rand() % 2560 + 1, 0 - obsTypes[rindex].GetRadius());
			obsvel = Vector2f(rand() % 2560 + 1, 1600);
			break;
		}

		Vector2f dir = obsvel - obspos; 
		float dist = sqrt((dir.x * dir.x) + (dir.y * dir.y));
		dir = dir / dist * 4.0f;

		Obstacle* newObs = new Obstacle(obsTypes[rindex], obspos); newObs->rigidbody.Accelarate(dir);
		obstacles->push_back(newObs); 
	}
}
