#include <SFML/Graphics.hpp>
#include <iostream>


const int width = 800;
const int height = 600;


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Infinite Axes");

    // center
    sf::Vector2f origin(width / 2, height / 2);

    sf::Vector2f offset(0, 0);
    float moveSpeed = 0.5f; // Скорость перемещения

    // axises
    sf::RectangleShape xAxis(sf::Vector2f(width, 2));
    xAxis.setFillColor(sf::Color::White);

    sf::RectangleShape yAxis(sf::Vector2f(height, 2));
    yAxis.setFillColor(sf::Color::White);
    yAxis.setRotation(90);

    // step and size
    int tickSpacing = 50;
    int tickSize = 10;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // moving camera
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) offset.y += moveSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) offset.y -= moveSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) offset.x += moveSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) offset.x -= moveSpeed;

        window.clear();

        // Обновляем позицию осей с учетом смещения
        xAxis.setPosition(0, origin.y + offset.y);
        yAxis.setPosition(origin.x + offset.x, 0);

        window.draw(xAxis);
        window.draw(yAxis);

        // tick Ox
        for (int x = (int)(origin.x + offset.x) % tickSpacing; x < width; x += tickSpacing)
        {
            sf::RectangleShape tick(sf::Vector2f(2, tickSize));
            tick.setFillColor(sf::Color::White);
            tick.setPosition(x, origin.y + offset.y - tickSize / 2);
            window.draw(tick);
        }

        // tick Oy
        for (int y = (int)(origin.y + offset.y) % tickSpacing; y < height; y += tickSpacing)
        {
            sf::RectangleShape tick(sf::Vector2f(2, tickSize));
            tick.rotate(90);
            tick.setFillColor(sf::Color::White);
            tick.setPosition(origin.x + offset.x - tickSize / 2 + 9, y); // CHECK
            window.draw(tick);
        }

        window.display();
    }

    return 0;
}