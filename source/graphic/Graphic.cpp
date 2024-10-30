#include "Graphic.h"

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
        float y_graph = tan(x) * 10;

        float screen_x = axises.getOrigin().x + x_graph + axises.getOffset().x;
        float screen_y = axises.getOrigin().y - (y_graph * axises.getScale()) + axises.getOffset().y;

        MyGraphic.append(sf::Vertex(sf::Vector2f(screen_x, screen_y), sf::Color::Yellow));
    }

    window.draw(MyGraphic);
}