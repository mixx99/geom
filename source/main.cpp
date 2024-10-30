#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphic/Axises.h"
#include "graphic/Graphic.h"
#include <iostream>


const int WIDTH = 1280;
const int HEIGHT= 720;


void show_fps(sf::Clock clock)
{
    float fps;
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime;
    currentTime = clock.getElapsedTime();
    fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
    std::cout << "fps =" << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
    previousTime = currentTime;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");

    Axises Axises(WIDTH, HEIGHT);
    Graphic graphic;
    sf::Clock clock;

    while (window.isOpen())
    {
        //show_fps(clock);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Axises.moveCamera();

        window.clear();

        graphic.drawParabolaForX(Axises, window, 0.01, 0, 0);
        graphic.drawHyperbolaForX(Axises, window, 10000);
        graphic.drawLineForX(Axises, window, 1, 0);
        graphic.DrawMyGraphic(Axises, window);

        window.draw(Axises.getXAxis());
        window.draw(Axises.getYAxis());
        Axises.drawTicks(window);

        window.display();
    }

    return 0;
}