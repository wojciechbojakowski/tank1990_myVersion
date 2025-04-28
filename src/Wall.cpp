#include "Wall.h"

Wall::Wall(float x, float y)
{
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color(150, 75, 0)); // brązowy - cegła
    shape.setPosition(x, y);
}

void Wall::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::RectangleShape &Wall::getShape()
{
    return shape;
}

Wall::Wall(float x, float y, Type type)
{
    this->type = type;
    shape.setSize(sf::Vector2f(40, 40));
    shape.setPosition(x, y);

    switch (type)
    {
        case Type::Brick:
            shape.setFillColor(sf::Color(150, 75, 0));  // Cegła
            break;
        case Type::Steel:
            shape.setFillColor(sf::Color(192, 192, 192));  // Stal
            break;
        case Type::Water:
            shape.setFillColor(sf::Color(0, 0, 255));  // Woda
            break;
    }
}