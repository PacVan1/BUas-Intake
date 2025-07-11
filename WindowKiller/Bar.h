#include <SFML\Graphics.hpp>
#pragma once

using namespace std;
using namespace sf;

class Bar
{
public: 
	Bar(Vector2f position, Color color, float maxBarLength, float barHeight, int* value, int* maxValue); 
	~Bar() {}

	Vector2f GetPosition() { return bar.getPosition(); } 
	void SetPosition(Vector2f position) { bar.setPosition(position); barOutline.setPosition(position); }
	void UpdateBarLength();
	void Draw(RenderWindow& window);
	
private:
	float barHeight;
	float maxBarWidth;
	float barWidth;
	int* value;
	int* maxValue;
	RectangleShape bar;
	RectangleShape barOutline;
};

