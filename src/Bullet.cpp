#include "Bullet.h"

Bullet::Bullet(float x, float y)
{
    shape.setRadius(5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    alive = true;
}

void Bullet::update()
{
    shape.move(0, -10);
    if (shape.getPosition().y < 0)
        alive = false;
}

void Bullet::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

bool Bullet::isAlive() const
{
    return alive;
}

sf::CircleShape &Bullet::getShape(){
    return shape;
}

void Bullet::kill(){
    alive=false;
}