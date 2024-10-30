#pragma once
#include "Axises.h"


class Graphic
{
public:
	Graphic();
	void drawParabolaForX(Axises& axises, sf::RenderWindow& window, float a, float b, float c);
	void drawHyperbolaForX(Axises& axises, sf::RenderWindow& window, float k);
	void drawLineForX(Axises& axises, sf::RenderWindow& window, float k, float b);
	void DrawMyGraphic(Axises& axises, sf::RenderWindow& window);
	void drawCanonParabola(Axises& axises, sf::RenderWindow& window, float& p);
	void drawSecretGraph(Axises& axises, sf::RenderWindow& window);
};