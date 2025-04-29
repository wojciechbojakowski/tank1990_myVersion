#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(float x, float y);
    void update(float dt);
    void draw(sf::RenderWindow &window);
    bool isAlive() const;
    sf::CircleShape &getShape();
    void kill();
private:
    sf::CircleShape shape;
    bool alive;
};
