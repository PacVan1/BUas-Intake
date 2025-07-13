#include <SFML\Graphics.hpp>
#pragma once

using namespace std;
using namespace sf;

class Button
{
public: 
	Button(Font& font) : text(font) {}
	Button(Font& font, string text, Vector2f size, Color normalColor, Color hoverColor, int charSize, int outlineThickness); 

	void SetFont(Font& font);
	void SetColor(Color color);
	void SetPosition(Vector2f position);
	void Draw(RenderWindow& window);
	bool isMouseOver(RenderWindow& window);

public:
	Color normalColor;
	Color hoverColor;

private: 
	RectangleShape button;
	Text text;
};

