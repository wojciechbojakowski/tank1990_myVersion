#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy(float x, float y);
    void update(float dt);
    void draw(sf::RenderWindow &window);
    sf::RectangleShape &getShape();
private:
    sf::RectangleShape shape;
    sf::Vector2f direction;
    sf::Clock changeDirClock;
};
