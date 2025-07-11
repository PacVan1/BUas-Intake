#include "ObstaclePool.h"

bool WallCollisionDetected(Obstacle& obs, float lBoundary, float rBoundary, float bBoundary, float uBoundary)
{
    return (obs.GetPosition().x < lBoundary || obs.GetPosition().x > rBoundary || obs.GetPosition().y < uBoundary || obs.GetPosition().y > bBoundary); 
}

void ObstaclePool::ObstacleInteraction(float deltaTime, ParticleSystem& particleSystem, ScoreSystem& scoreSystem)
{
    auto wallDetected = [](Obstacle* obs) { return WallCollisionDetected(*obs, 0.0f - obs->GetRadius(), 1920 + obs->GetRadius(), 1200 + obs->GetRadius(), 0.0f - obs->GetRadius()); }; 

    for (Obstacle* obs1 : obstacles)
    {
        for (Obstacle* obs2 : obstacles)
            if (obs1 != obs2)
                if (collision.CollisionDetected(*obs1, *obs2)) 
                {
                    collision.CollisionResponse(*obs1, *obs2); 
                    obs1->GetHit(particleSystem, obs2->GetDamage());  
                    obs2->GetHit(particleSystem, obs1->GetDamage()); 
                }

        for (Obstacle* playerObs : playerObstacles)
        {
            if (collision.CollisionDetected(*obs1, *playerObs))
            {
                collision.CollisionResponse(*obs1, *playerObs);
                obs1->GetHit(particleSystem, playerObs->GetDamage()); 
                playerObs->GetHit(particleSystem, obs1->GetDamage());

                if (obs1->isDead())
                {
                    scoreSystem.AddScore(obs1->GetDamage());
                }
            }
        }
    }

    obstacles.erase(remove_if(obstacles.begin(), obstacles.end(), [](Obstacle* obs) { return obs->isDead(); }), obstacles.end());
    obstacles.erase(remove_if(obstacles.begin(), obstacles.end(), wallDetected), obstacles.end()); 
    playerObstacles.erase(remove_if(playerObstacles.begin(), playerObstacles.end(), [](Obstacle* obs) { return obs->isDead(); }), playerObstacles.end());
    playerObstacles.erase(remove_if(playerObstacles.begin(), playerObstacles.end(), wallDetected), playerObstacles.end());
}

void ObstaclePool::Move(float deltaTime)
{
    for (Obstacle* obs : obstacles) 
    {
        obs->Update();
    }
    for (Obstacle* obs : playerObstacles) 
    {
        obs->Update();  
    }
}

void ObstaclePool::Draw(RenderWindow& window)
{
    for (Obstacle* obs : obstacles)
    {
        obs->Draw(window);
    }    
    for (Obstacle* obs : playerObstacles)
    {
        obs->Draw(window);
    }
}
