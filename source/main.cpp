#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphic/Axises.h"

const int WIDTH = 800;
const int HEIGHT= 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Axises Axises(WIDTH, HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Axises.moveCamera();

        window.clear();
        window.draw(Axises.getXAxis());
        window.draw(Axises.getYAxis());
        Axises.drawTicks(window);
        window.display();
    }

    return 0;
}