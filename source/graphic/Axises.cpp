#include "Axises.h"
#include <iostream>
Axises::Axises(const int& width, const int& height)
    :
    width(width),
    height(height)
{
    // center
    Axises::origin.x = width / 2;
    Axises::origin.y = height / 2;

    Axises::offset.x = 0;
    Axises::offset.y = 0;
    Axises::moveSpeed = 0.5f; // Скорость перемещения

    // axises
    xAxis.setSize(sf::Vector2f(width, 2));
    xAxis.setFillColor(sf::Color::White);

    yAxis.setSize(sf::Vector2f(height, 2));
    yAxis.setFillColor(sf::Color::White);
    yAxis.setRotation(90);

    // step and size
    tickSpacing = 50;
    tickSize = 10;
    scale = 1.0f;
}

void Axises::drawTicks(sf::RenderWindow& window)
{
    // tick Ox
    for (int x = (int)(getOrigin().x + getOffset().x) % getTickSpacing(); x < width; x += getTickSpacing())
    {
        sf::RectangleShape tick(sf::Vector2f(2, getTickSize()));
        tick.setFillColor(sf::Color::White);
        tick.setPosition(x, getOrigin().y + getOffset().y - getTickSize() / 2);
        window.draw(tick);
    }

    // tick Oy
    for (int y = (int)(getOrigin().y + getOffset().y) % getTickSpacing(); y < height; y += getTickSpacing())
    {
        sf::RectangleShape tick(sf::Vector2f(2, getTickSize()));
        tick.rotate(90);
        tick.setFillColor(sf::Color::White);
        tick.setPosition(getOrigin().x + getOffset().x - getTickSize() / 2 + 9, y); // CHECK
        window.draw(tick);
    }
}
void Axises::moveCamera()
{
    float deltaTime = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    deltaTime = deltaTime / 800;
    // moving camera
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveYAxis(getMoveSpeed() * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveYAxis(-(getMoveSpeed() * deltaTime));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveXAxis(getMoveSpeed() * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveXAxis(-(getMoveSpeed() * deltaTime));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        setScale(getScale() + 0.01f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        setScale(getScale() - 0.01f);
    }


    // Обновляем позицию осей с учетом смещения
    getXAxis().setPosition(0, getOrigin().y + getOffset().y);
    getYAxis().setPosition(getOrigin().x + getOffset().x, 0);
}

void Axises::moveYAxis(float delta)
{
    Axises::offset.y += delta;
}
void Axises::moveXAxis(float delta)
{
    Axises::offset.x += delta;
}
float Axises::getMoveSpeed()
{
    return Axises::moveSpeed;
}
sf::RectangleShape& Axises::getXAxis()
{
    return Axises::xAxis;
}
sf::RectangleShape& Axises::getYAxis()
{
    return Axises::yAxis;
}
sf::Vector2f& Axises::getOrigin()
{
    return Axises::origin;
}
sf::Vector2f& Axises::getOffset()
{
    return Axises::offset;
}
int Axises::getTickSize()
{
    return tickSize;
}
int Axises::getTickSpacing()
{
    return tickSpacing;
}
void Axises::setXAxisPosition(sf::Vector2f& position)
{
    Axises::xAxis.setPosition(position);
}
void Axises::setYAxisPosition(sf::Vector2f& position)
{
    Axises::yAxis.setPosition(position);
}
void Axises::setScale(float newScale)
{
    Axises::scale = newScale;
}
float Axises::getScale()
{
    return Axises::scale;
}