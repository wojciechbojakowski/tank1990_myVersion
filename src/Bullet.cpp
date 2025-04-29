#include "Bullet.h"

Bullet::Bullet(float x, float y)//dodać kierunek co pozwoli strzelać w róźnych kierunkach
{
    shape.setRadius(5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    alive = true;
}

void Bullet::update(float dt)
{
    shape.move(0, -10*17*dt);
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