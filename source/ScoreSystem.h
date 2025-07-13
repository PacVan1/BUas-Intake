#include <SFML\Graphics.hpp> 
#include "UI.h"
#pragma once

using namespace sf;

class ScoreSystem
{
public: 
	ScoreSystem(UI* ui) : ui(ui), score(0), highscore(0) {}
	int GetScore() { return score; }
	int GetHighscore() { return highscore; }
	void SetScore(int score) { this->score = score; ui->UpdateScore(this->score); } 
	void SetHighscore(int highscore) { this->highscore = highscore; }
	void AddScore(int increment) { score += increment; ui->UpdateScore(score); }  

private:
	UI* ui;
	int score; 
	int highscore;
};

