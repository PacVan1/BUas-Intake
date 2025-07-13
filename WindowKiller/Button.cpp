#include "Button.h"

Button::Button(Font& font, string text_, Vector2f size, Color normalColor, Color hoverColor, int charSize, int outlineThickness) : 
	normalColor(normalColor),
	hoverColor(hoverColor), 
	text(font)
{
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

	float buttonw = button.getLocalBounds().size.x - button.getOutlineThickness(); 
	float buttonh = button.getLocalBounds().size.y - button.getOutlineThickness(); 
	
	float textw = text.getLocalBounds().size.x;  
	float texth = text.getLocalBounds().size.y;  

	float textx = position.x + ((buttonw - textw) / 2);
	float texty = position.y + ((buttonh - texth) / 2); 

	text.setPosition(Vector2f(textx, texty));
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
	float right = left + button.getLocalBounds().size.x; 
	float bottom = top + button.getLocalBounds().size.y;

	return (mouseX > left && mouseX < right && mouseY > top && mouseY < bottom);
}


