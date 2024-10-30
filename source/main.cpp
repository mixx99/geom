#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphic/Axises.h"
#include "graphic/Graphic.h"
#include <iostream>


const int WIDTH = 1280;
const int HEIGHT= 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");
    float p = 0;
    Axises Axises(WIDTH, HEIGHT);
    Graphic graphic;

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
        //graphic.drawParabolaForX(Axises, window, 0.01, 0, 0);
        //graphic.drawHyperbolaForX(Axises, window, 10000);
        //graphic.drawLineForX(Axises, window, 1, 0);
        //graphic.DrawMyGraphic(Axises, window);

        //std::cout << "P = " << p << '\n';
        //graphic.drawCanonParabola(Axises, window, p);

        graphic.drawSecretGraph(Axises, window);

        window.draw(Axises.getXAxis());
        window.draw(Axises.getYAxis());
        Axises.drawTicks(window);

        window.display();
    }

    return 0;
}