#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(float x, float y);
    Bullet(float x, float y, float dx, float dy);
    void update(float dt);
    void draw(sf::RenderWindow &window);
    bool isAlive() const;
    sf::CircleShape &getShape();
    void kill();
private:
    sf::CircleShape shape;
    bool alive;
    float directX;
    float directY;
};
