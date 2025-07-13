#include "Collision.h"

bool Collision::CollisionDetected(Obstacle& obs1, Obstacle& obs2)
{
	float dx = obs2.GetPosition().x - obs1.GetPosition().x;
	float dy = obs2.GetPosition().y - obs1.GetPosition().y;
	int radiiSum = obs1.GetCollider().GetRadius() + obs2.GetCollider().GetRadius();

	float dist = sqrt((dx * dx) + (dy * dy));

	if (dist < radiiSum) // distance between centers smaller than combined radius?
	{
		// displace both objects 50% of the overlap so it's a clean collision
		Vector2f displacement = 0.5f * (Vector2f(dx, dy) / dist) * (radiiSum - dist);
		obs1.SetPosition(obs1.GetPosition() - displacement);
		obs2.SetPosition(obs2.GetPosition() + displacement);
		return true;
	}

	return false;
}

void Collision::CollisionResponse(Obstacle& obs1, Obstacle& obs2)
{
	// 2-Dimensional Elastic Collisions without Trigonometry by Chad Berchek
	// https://www.vobarian.com/collisions/2dcollisions2.pdf

	Vector2f n = obs2.GetPosition() - obs1.GetPosition();							  
	Vector2f un = n / sqrt((n.x * n.x) + (n.y * n.y)); // unit normal
	Vector2f ut = Vector2f(-un.y, un.x);			   // unit tangent

	// take the dot product of the two vectors and the two axis (tangent and normal)
	float s1n  = un.x * obs1.GetVelocity().x + un.y * obs1.GetVelocity().y; // scalar normal 1
	float fs1t = ut.x * obs1.GetVelocity().x + ut.y * obs1.GetVelocity().y; // final scalar tangent 1
	float s2n  = un.x * obs2.GetVelocity().x + un.y * obs2.GetVelocity().y; // scalar normal 2
	float fs2t = ut.x * obs2.GetVelocity().x + ut.y * obs2.GetVelocity().y; // final scalar tangent 2

	// conservation of momentum and conversation of kinetic energy formula for one dimensional elastic collision
	int mass1 = obs1.GetRigidbody().GetMass();
	int mass2 = obs2.GetRigidbody().GetMass();
	float fs1n = (s1n * (mass1 - mass2) + 2 * mass2 * s2n) / (mass1 + mass2); // final scalar normal 1
	float fs2n = (s2n * (mass2 - mass1) + 2 *  mass1 * s1n) / (mass1 + mass2);  // final scalar normal 2

	Vector2f fv1 = (un * fs1n) + (ut * fs1t); // final vector 1
	Vector2f fv2 = (un * fs2n) + (ut * fs2t); // final vector 2

	obs1.rigidbody.SetVelocity(fv1);
	obs2.rigidbody.SetVelocity(fv2);
}
