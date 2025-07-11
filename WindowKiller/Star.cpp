///////////////////////////////
// Headers
///////////////////////////////
#include "Star.h"

///////////////////////////////
// Constructors / Destructors
///////////////////////////////
Star::Star(float y, float velocity, float radius, int brightness) :
	shape(radius, 8),
	velocity(velocity)
{
	shape.setPosition({ 0.0f, y });
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setFillColor(Color(brightness, brightness, brightness, 255));
}

///////////////////////////////
// Methods
///////////////////////////////
void Star::Move()
{
	shape.setPosition(shape.getPosition() + Vector2f(1.0f, 0.0f) * velocity);
}

void Star::Draw(RenderWindow& window)
{
	window.draw(shape);
}