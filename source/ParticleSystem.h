#include <SFML\Graphics.hpp>
#include "Particle.h"
#include "list"
#include "iterator"
#pragma once

using namespace std;
using namespace sf;

class ParticleSystem
{
public: 
	ParticleSystem() {}
	~ParticleSystem() {}

	void Explode(Particle particle, Vector2f position, int particleAmount, int particleSpeed);
	void Update(RenderWindow& window, float deltaTime);

public:
	list<Particle*> particles;
};

