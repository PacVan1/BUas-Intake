///////////////////////////////
// Headers
///////////////////////////////
#include "Bar.h"

///////////////////////////////
// Constructors / Destructors 
///////////////////////////////
Bar::Bar(Vector2f position, Color color, float maxBarWidth, float barHeight, int* value, int* maxValue) :
	maxBarWidth(maxBarWidth),
	barHeight(barHeight),
	barWidth(maxBarWidth), 
	value(value),
	maxValue(maxValue)
{
	bar.setFillColor(color);
	bar.setPosition(position.x, position.y + barOutline.getOutlineThickness());
	bar.setSize({ maxBarWidth, barHeight });  
	bar.setOrigin({ maxBarWidth / 2.0f, 0.0f}); 
	barOutline.setFillColor(Color::Transparent);
	barOutline.setOutlineColor(color);
	barOutline.setOutlineThickness(2);
	barOutline.setPosition(position.x, position.y + barOutline.getOutlineThickness());
	barOutline.setSize({ maxBarWidth, barHeight });
	barOutline.setOrigin({ maxBarWidth / 2.0f, 0.0f });

	
}

///////////////////////////////
// Methods
/////////////////////////////// 
void Bar::UpdateBarLength()
{
	printf("max: %i now: %i\n", *maxValue, *value);
	barWidth = (float)*value / (float)*maxValue * maxBarWidth;  
	bar.setSize({ barWidth, barHeight });
}

void Bar::Draw(RenderWindow& window)
{
	window.draw(bar);
	window.draw(barOutline);
}
