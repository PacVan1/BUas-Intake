#include "Gun.h"
#include <iterator>
#include <cmath>

Gun::Gun(Obstacle* owner, float bulletSpeed, float fireRate) :
	barrel(Vector2f(20.0f, 10.0f)),
	projectile({ 0.0f, 0.0f }, Color::White, 2, 0.0f, 4, 1, 1), 
	direction(Vector2f(0.0f, 0.0f)),
	bulletSpeed(bulletSpeed), 
	fireRate(fireRate),
	owner(owner),
	currentTime(0.0f), 
	canFire(true)
{
	this->position = owner->GetPositionP();

	barrel.setRotation(0);
	barrel.setPosition(owner->GetPosition() + direction * (float)owner->GetCollider().GetRadius());
	barrel.setOrigin(0.0f, barrel.getSize().y * 0.5f);
	barrel.setFillColor(Color::Transparent);
	barrel.setOutlineColor(owner->GetShape().getOutlineColor());
	barrel.setOutlineThickness(owner->GetShape().getOutlineThickness());
}

Gun::~Gun() {}

void Gun::Reload(float deltaTime)
{
	if (!canFire)
	{
		currentTime += deltaTime;

		if (currentTime > fireRate)
		{
			currentTime -= fireRate;
			canFire = true;
		}
	}
}

void Gun::Fire(ParticleSystem& particleSystem, ObstaclePool& obstaclePool)
{
	if (canFire && Mouse::isButtonPressed(Mouse::Left))
	{
		Obstacle* newProjectile = new Obstacle(projectile, barrel.getPosition() + direction * 20.0f); newProjectile->rigidbody.SetVelocity(direction * bulletSpeed); 
		obstaclePool.playerObstacles.push_back(newProjectile);  
		particleSystem.Explode(projectile.CreateParticle(), owner->GetPosition(), 8, 5);
		Knockback();

		canFire = false;
	}
}

void Gun::Aim(Vector2i target)
{
	direction = Vector2f(target.x, target.y) - owner->GetPosition();
	direction /= sqrt((direction.x * direction.x) + (direction.y * direction.y));
}

void Gun::Update(RenderWindow& window, float deltaTime)
{
	Reload(deltaTime);
	Aim(Mouse::getPosition(window));
}

void Gun::Knockback()
{
	owner->rigidbody.Accelarate(-direction);
}

void Gun::Draw(RenderWindow& window)
{
	float barrelAngle = (atan2(direction.y, direction.x) * 180) / 3.141592f;
	barrel.setRotation(barrelAngle);  
	barrel.setPosition(owner->GetPosition()); 

	window.draw(barrel);
}

