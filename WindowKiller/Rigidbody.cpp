///////////////////////////////
// Headers
///////////////////////////////
#include "Rigidbody.h"

///////////////////////////////
// Constructors / Destructors 
///////////////////////////////
Rigidbody::Rigidbody() : 
	position_p(new Vector2f(0.0f, 0.0f)),
	friction(0),
	velocity(Vector2f(0.0f, 0.0f)),
	accelaration(Vector2f(0.0f, 0.0f)),
	mass(1) {}

Rigidbody::Rigidbody(Vector2f velocity, float friction, int mass) :
	position_p(new Vector2f(0.0f, 0.0f)), 
	friction(friction), 
	velocity(velocity), 
	accelaration(Vector2f(0.0f, 0.0f)), 
	mass(mass) {} 

Rigidbody::Rigidbody(Vector2f* position, Vector2f velocity, float friction, int mass) :
	position_p(position),
	friction(friction),
	velocity(velocity),
	accelaration(Vector2f(0.0f, 0.0f)),
	mass(mass) {}

///////////////////////////////
// Methods
///////////////////////////////
void Rigidbody::Move()
{
	*position_p += velocity;
	Accelarate(velocity * -friction);
}
