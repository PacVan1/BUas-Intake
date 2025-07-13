///////////////////////////////
// Headers
///////////////////////////////
#include "CircleCollider.h"

///////////////////////////////
// Constructors / Destructors
///////////////////////////////
CircleCollider::CircleCollider() : 
	position_p(new Vector2f(0.0f, 0.0f)),
	radius(10) {}

CircleCollider::CircleCollider(int radius) : 
	position_p(new Vector2f(0.0f, 0.0f)),
	radius(radius) {}

CircleCollider::CircleCollider(Vector2f* position, int radius) : 
	position_p(position),
	radius(radius) {}