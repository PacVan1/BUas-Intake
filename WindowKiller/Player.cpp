///////////////////////////////
// Headers
///////////////////////////////
#include "Player.h"

///////////////////////////////
// Constructors / Destructors
///////////////////////////////
Player::Player() :
	Obstacle({ 0.0f, 0.0f }, Color::White, 10, 0.01f, 100, 40, 2),
	gun(this, 10, 0.2f),
    healthbar(position + Vector2f(0.0f, 14.0f), Color::Red, 30.0f, 6.0f, &health, &maxHealth) {}

Player::Player(Vector2f position, Color color, int radius, bool friction, int damage, int health, int mass) :
	Obstacle(position, color, radius, friction, damage, health, 1), 
	gun(this, 5.0f, 0.2f),
    healthbar(position + Vector2f(0.0f, 14.0f), Color::Red, 20.0f, 6.0f, &this->health, &maxHealth) {}

void Player::UpdateGun(ParticleSystem& particleSystem, ObstaclePool& obstaclePool, RenderWindow& window, float deltaTime)
{
    gun.Fire(particleSystem, obstaclePool);
    gun.Update(window, deltaTime); 
} 

void Player::Draw(RenderWindow& window)
{
    Obstacle::Draw(window);

    gun.Draw(window);

    healthbar.UpdateBarLength();
    healthbar.SetPosition(position + Vector2f(0.0f, 24.0f)); 
    healthbar.Draw(window);
}

void Player::Move()
{
    if (Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        rigidbody.Accelarate(Vector2f(-0.2f, 0.0f));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
        rigidbody.Accelarate(Vector2f(0.2f, 0.0f));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        rigidbody.Accelarate(Vector2f(0.0f, -0.2f));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
        rigidbody.Accelarate(Vector2f(0.0f, 0.2f));
    }

    if (position.x < GetRadius())
    {
        position.x = GetRadius();
        rigidbody.velocity.x = -rigidbody.velocity.x;
    }
    if (position.x > 2560 - GetRadius()) 
    {
        position.x = 2560 - GetRadius();
        rigidbody.velocity.x = -rigidbody.velocity.x; 
    }
    if (position.y < GetRadius()) 
    {
        position.y = GetRadius(); 
        rigidbody.velocity.y = -rigidbody.velocity.y; 
    } 
    if (position.y > 1600 - GetRadius())
    {
        position.y = 1600 - GetRadius();
        rigidbody.velocity.y = -rigidbody.velocity.y; 
    }

    Obstacle::Move(); 
}
