#include <SFML\Graphics.hpp>
#include "Button.h"
#pragma once

using namespace std;
using namespace sf;

class UI
{
public:
	UI(int score, int* state); 
	~UI() {}

	void UpdateScore(int score) { minerals.setString("Minerals: " + to_string(score)); }
	void StartScreen(RenderWindow& window);
	void PlayScreen(RenderWindow& window);
	void GameOverScreen(RenderWindow& window);

private:
	Font fr;
	Font fb;
	Button startButton;
	Button restartButton;
	Button mainButton;
	Button quitButton;
	Text title;
	Text gameOver;
	Text minerals;
	Text controls;
	Text gameBy;

	int* state;
};

