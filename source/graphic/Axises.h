#pragma once
#include <SFML/Graphics.hpp>

class Axises
{
	int width;
	int height;

	sf::Vector2f origin;
	sf::Vector2f offset;

	float moveSpeed;
	float scale;

	sf::RectangleShape xAxis;
	sf::RectangleShape yAxis;
	int tickSpacing;
	int tickSize;
	sf::Clock clock;
public:
	Axises(const int& width, const int& height);
	void moveYAxis(float delta);
	void moveXAxis(float delta);
	void drawTicks(sf::RenderWindow& window);
	void moveCamera();
public: // getters
	float getMoveSpeed();
	sf::RectangleShape& getXAxis();
	sf::RectangleShape& getYAxis();
	sf::Vector2f& getOrigin();
	sf::Vector2f& getOffset();
	int getTickSpacing();
	int getTickSize();
	float getScale();
public: // setters
	void setXAxisPosition(sf::Vector2f& position);
	void setYAxisPosition(sf::Vector2f& position);
	void setScale(float newScale);
};

