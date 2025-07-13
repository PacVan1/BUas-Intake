///////////////////////////////
// Headers
///////////////////////////////
#include "Particle.h"

///////////////////////////////
// Constructors / Destructors
///////////////////////////////
Particle::Particle() : 
	shape(2, 30),
	rigidbody(&this->position, Vector2f(0.0f, 0.0f), 0.0f, 1)
{
	shape.setOrigin(Vector2f(GetRadius(), GetRadius()));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(2);

	position = Vector2f(0.0f, 0.0f);
}

Particle::Particle(Particle particle, Vector2f position, Vector2f velocity) : 
	shape(particle.GetRadius(), 30), 
	rigidbody(&this->position, velocity, particle.rigidbody.GetFriction(), 1)
{
	shape.setOrigin(Vector2f(particle.GetRadius(), particle.GetRadius()));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(particle.GetShape().getOutlineColor());
	shape.setOutlineThickness(particle.GetShape().getOutlineThickness());
	 
	this->position = position; 
}

Particle::Particle(Vector2f position, Vector2f velocity, Color color, int radius, int outlineThickness, bool friction) :
	shape(radius, 30),
	rigidbody(&this->position, velocity, friction, 1) 
{
	shape.setOrigin(Vector2f(radius, radius));
	shape.setFillColor(Color::Transparent);
	shape.setOutlineColor(color);
	shape.setOutlineThickness(outlineThickness);

	this->position = position;
}

Particle::Particle(Color color, int radius, int outlineThickness, bool friction) : 
	shape(radius, 30), 
	rigidbody() 
{
	shape.setOrigin(Vector2f(radius, radius));
	shape.setFillColor(Color::Transparent);
	shape.setOutlineColor(color);
	shape.setOutlineThickness(outlineThickness);
}

///////////////////////////////
// Methods
///////////////////////////////
bool Particle::FadeOut(unsigned int fadeOutSpeed)
{
	shape.setOutlineColor(shape.getOutlineColor() - sf::Color{ 0, 0, 0, 6 });

	if (shape.getOutlineColor().a <= 0)
		return true;

	return false;
}

void Particle::Draw(RenderWindow& window)
{
	shape.setPosition(position); 

	window.draw(shape);
}



