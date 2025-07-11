#include "Button.h"

Button::Button(Font& font, string text_, Vector2f size, Color normalColor, Color hoverColor, int charSize, int outlineThickness) : 
	normalColor(normalColor),
	hoverColor(hoverColor)
{
	text.setFont(font); 
	text.setString(text_);
	text.setFillColor(normalColor);  
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(Color(0, 0, 0, 120));
	button.setOutlineColor(normalColor); 
	button.setOutlineThickness(outlineThickness); 
}

void Button::SetFont(Font& font)
{
	text.setFont(font);
}

void Button::SetColor(Color color)
{
	text.setFillColor(color);   
	button.setOutlineColor(color);
}

void Button::SetPosition(Vector2f position)
{
	button.setPosition(position);

	float buttonw = button.getLocalBounds().width - button.getOutlineThickness(); 
	float buttonh = button.getLocalBounds().height - button.getOutlineThickness(); 
	
	float textw = text.getLocalBounds().width;  
	float texth = text.getLocalBounds().height;  

	float textx = position.x + ((buttonw - textw) / 2);
	float texty = position.y + ((buttonh - texth) / 2); 

	text.setPosition(textx, texty);
}

void Button::Draw(RenderWindow& window)
{
	window.draw(button);
	window.draw(text); 
}

bool Button::isMouseOver(RenderWindow& window)
{
	float mouseX = Mouse::getPosition(window).x;  
	float mouseY = Mouse::getPosition(window).y;

	float left = button.getPosition().x;  
	float top = button.getPosition().y;  
	float right = left + button.getLocalBounds().width; 
	float bottom = top + button.getLocalBounds().height;

	return (mouseX > left && mouseX < right && mouseY > top && mouseY < bottom);
}


