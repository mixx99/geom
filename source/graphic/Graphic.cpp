#include "Graphic.h"
#include <iostream>
Graphic::Graphic()
{}

void Graphic::drawParabolaForX(Axises& axises, sf::RenderWindow& window, float a, float b, float c) {
    sf::VertexArray parabola(sf::LinesStrip);

    float xl = -abs(axises.getOffset().x) - axises.getOrigin().x;

    for (float x = xl; x < -xl; x += 1.0f) {

        float x_graph = x;
        float y_graph = a * x_graph * x_graph + b * x_graph + c;

        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        parabola.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Green));
    }

    window.draw(parabola);
}

void Graphic::drawHyperbolaForX(Axises& axises, sf::RenderWindow& window, float k)
{
    sf::VertexArray hyperbola(sf::LinesStrip);
    float xl = -abs(axises.getOffset().x) - axises.getOrigin().x;

    for (float x = xl; x < -xl; x += 1.0f) {

        float x_graph = x;
        float y_graph = k / x;

        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        hyperbola.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Red));
    }

    window.draw(hyperbola);
}

void Graphic::drawLineForX(Axises& axises, sf::RenderWindow& window, float k, float b)
{
    sf::VertexArray line(sf::LinesStrip);
    float xl = -abs(axises.getOffset().x) - axises.getOrigin().x;

    for (float x = xl; x < -xl; x += 1.0f) {

        float x_graph = x;
        float y_graph = k*x + b;

        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        line.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Cyan));
    }

    window.draw(line);
}

void Graphic::DrawMyGraphic(Axises& axises, sf::RenderWindow& window)
{
    sf::VertexArray MyGraphic(sf::LinesStrip);
    float xl = -abs(axises.getOffset().x) - axises.getOrigin().x;

    for (float x = xl; x < -xl; x += 1.0f) {

        float x_graph = x;
        float y_graph = tan(x*0.01) * 50;         // tan
        //float y_graph = sin(x * 0.1) * 50;        // sin
        //float y_graph = cos(x * 0.1) * 50;        // cos
        //float y_graph = abs(cos(x * 0.1)) * 50;   // |cos|

        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        MyGraphic.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Yellow));
    }

    window.draw(MyGraphic);
}

void Graphic::drawCanonParabola(Axises& axises, sf::RenderWindow& window, float& p)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p += 0.001f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  p -= 0.001f;

    sf::VertexArray CanonParabola(sf::LinesStrip);

    float xl = -abs(axises.getOffset().x) - axises.getOrigin().x;

    for (float y = xl; y < -xl; y += 1.0f)
    {
        float y_graph = y;
        float x_graph = y * y * p * 2;
        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;
        
        CanonParabola.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color(200, 100, 250)));
    }
    window.draw(CanonParabola);
}


void Graphic::drawSecretGraph(Axises& axises, sf::RenderWindow& window)
{
    sf::VertexArray MyGraphicUpper(sf::LinesStrip);
    float xl = -abs(axises.getOffset().x) - axises.getOrigin().x;

    for (float x = xl; x < -xl; x += 1.0f) {

        float x_graph = x;
        float y_graph;
        y_graph = pow(1 - (pow(abs(x*0.05) - 1, 2)), 0.5) * 50;


        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        MyGraphicUpper.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Yellow));
    }

    window.draw(MyGraphicUpper);

    sf::VertexArray MyGraphicDown(sf::LinesStrip);
    
    for (float x = xl; x < -xl; x += 1.0f) {

        float x_graph = x;
        float y_graph;
        y_graph = (acos(1 - abs(x*0.05)) - 3.1415) * 50;


        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        MyGraphicDown.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Yellow));
    }
    window.draw(MyGraphicDown);


}