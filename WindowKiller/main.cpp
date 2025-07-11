#include <SFML\Graphics.hpp>  
#include <ctime>
#include "Game.h"
#include "Collision.h"
#include "ObstacleSpawner.h"
#include "Player.h"
#include "Obstacle.h"
#include <list>
#include <vector>
#include <iterator>

using namespace std;
using namespace sf;

static const float VIEW_WIDTH = 512.0f;
static const float VIEW_HEIGHT = 512.0f;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Game", Style::Fullscreen, settings);

    Game game;

    srand((unsigned)time(0));
     
    Collision collision;

    sf::Clock clock;
    float deltaTime = 0.0f;
    
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        window.setFramerateLimit(60);

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed: window.close(); break;
            case Event::MouseButtonPressed: break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            window.close();
        }

        window.clear(Color(0, 0, 20, 255));
        game.Update(window, deltaTime);  
        window.display();
    }

    return 0;
}