#pragma once
#include <SFML/Graphics.hpp>

class Wall
{
public:
    enum class Type { Brick, Steel, Water };

    Wall(float x, float y, Type type);
    Wall(float x, float y);
    void draw(sf::RenderWindow &window);
    sf::RectangleShape &getShape();
private:
    sf::RectangleShape shape;
    Type type;
};
