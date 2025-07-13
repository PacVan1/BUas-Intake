///////////////////////////////
// Headers
///////////////////////////////
#include "ParticleSystem.h"

///////////////////////////////
// Methods
///////////////////////////////
void ParticleSystem::Explode(Particle particle, Vector2f position, int particleAmount, int particleSpeed)
{
    for (int i = 0; i < particleAmount; i++)
    {
	    Vector2f velocity = Vector2f(rand() % particleSpeed - 2, rand() % particleSpeed - 2);
	    particles.push_back(new Particle(particle, position, velocity)); 
    }
}

void ParticleSystem::Update(RenderWindow& window, float deltaTime)
{
    if (!particles.empty()) 
    {
        for (Particle* particle : particles) 
        {
            particle->Move(); 
            particle->Draw(window); 
        }
        particles.erase(remove_if(particles.begin(), particles.end(), [](Particle* particle) { return particle->FadeOut(6); }), particles.end()); 
    }
}
