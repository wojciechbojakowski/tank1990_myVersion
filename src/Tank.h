#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>
#include "Wall.h"

class Tank
{
public:
    Tank(float x, float y);
    void move(float dx, float dy);
    void draw(sf::RenderWindow &window);
    void move(float dx, float dy, std::list<Wall> &walls, float dt);
    Bullet shoot();
    Bullet shootWithMouse(float dx, float dy);
private:
    sf::RectangleShape shape;
};
