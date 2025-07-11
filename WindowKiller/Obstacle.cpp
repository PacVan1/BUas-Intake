#include "Obstacle.h"

Obstacle::Obstacle(Obstacle& obs, Vector2f position) :
	shape(obs.GetShape().getRadius()),
	collider(&this->position, obs.GetShape().getRadius()),
	rigidbody(&this->position, { 0.0f, 0.0f }, obs.GetRigidbody().GetFriction(), obs.GetRigidbody().GetMass()),
	position(position),
	damage(obs.GetDamage()),
	health(obs.GetHealth()),
	maxHealth(obs.GetHealth()),
	dead(false)
{
	shape.setPosition(position); 
	shape.setOrigin(obs.GetShape().getRadius(), obs.GetShape().getRadius());  
	shape.setFillColor(Color::Transparent);  
	shape.setOutlineColor(obs.GetShape().getOutlineColor());  
	shape.setOutlineThickness(obs.GetShape().getOutlineThickness());
	shape.setPointCount(obs.GetShape().getPointCount());
}

Obstacle::Obstacle(Vector2f position, Color color, int radius, float friction, int damage, int health, int mass) :
	shape(radius, 30),
	collider(&this->position, radius),
	rigidbody(&this->position, { 0.0f, 0.0f }, friction, mass),
	position(position),
	damage(damage),
	health(health),
	maxHealth(health),
	dead(false)
{
	shape.setPosition(position);
	shape.setOrigin(radius, radius); 
	shape.setFillColor(Color::Transparent);
	shape.setOutlineColor(color);
	shape.setOutlineThickness(3);
}

void Obstacle::Draw(RenderWindow& window)
{
	shape.setPosition(position); 
	window.draw(shape); 
}

Particle Obstacle::CreateParticle()
{
	return Particle(GetColor(), int(GetRadius() / 2.0f), int(shape.getOutlineThickness() / 2.0f), 0.0f);
}

void Obstacle::GetHit(ParticleSystem& particleSystem, int damage)
{
	particleSystem.Explode(CreateParticle(), position, 4, 5);
	DecreaseHealth(damage); 
}

void Obstacle::Update()
{
	Move();
}

void Obstacle::Move()
{
	rigidbody.Move(); 
}

void Obstacle::DecreaseHealth(int damage)
{
	health -= damage; 
	if (health <= 0) 
	{
		dead = true;
	}
	else { dead = false; }
}

