#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Wall.h"

class Enemy
{
public:
    Enemy(float x, float y);
    void update(float dt,  std::list<Wall> &walls);
    void draw(sf::RenderWindow &window);
    sf::RectangleShape &getShape();
private:
    sf::RectangleShape shape;
    sf::Vector2f direction;
    sf::Clock changeDirClock;
};
