///////////////////////////////
// Headers
///////////////////////////////
#include "Starfield.h"

///////////////////////////////
// Constructors
///////////////////////////////
Starfield::Starfield(float rate) : 
	rate(rate),
	currentTime(0.0f) {}

auto Border = [](Star* star) { return star->GetX() > 1920; };

///////////////////////////////
// Methods
///////////////////////////////
void Starfield::Update(RenderWindow& window, float deltaTime)
{
	currentTime += deltaTime;

	if (currentTime > rate)
	{
		CreateStar(5, 2, 150);
		currentTime -= rate; 
	}

	for (Star* star : starfield)
	{
		star->Move();
		star->Draw(window);
	}

	starfield.erase(remove_if(starfield.begin(), starfield.end(), Border), starfield.end()); 
}

void Starfield::CreateStar(float velocity, float radius, int brightness)
{
	float ry = rand() % 1200 + 1;
	float rvel = rand() % int((velocity + 3) + 1 - (velocity - 3)) + (velocity - 3); 

	radius *= 10; 
	float rradius = rand() % int((radius + 10) + 1 - (radius - 10)) + (radius - 10); 
	rradius /= 10;

	float rbright = rand() % int((brightness + 100) + 1 - (brightness - 100)) + (brightness - 100); 

	starfield.push_back(new Star(ry, rvel, rradius, rbright));  
}

