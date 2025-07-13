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
#include <optional>

using namespace std;
using namespace sf;

static const float VIEW_WIDTH = 2560.0f;
static const float VIEW_HEIGHT = 1600.0f;

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(Vector2u(VIEW_WIDTH, VIEW_HEIGHT)),
        "Game",
        sf::State::Fullscreen,
        settings
    );


    Game game;

    srand((unsigned)time(0));
     
    Collision collision;

    sf::Clock clock;
    float deltaTime = 0.0f;
    
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        window.setFramerateLimit(60);

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (event->is<sf::Event::MouseButtonPressed>()) {
                // Handle mouse press if needed
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)) {
            window.close();
        }

        window.clear(sf::Color(0, 0, 20, 255));
        game.Update(window, deltaTime);
        window.display();
    }


    return 0;
}