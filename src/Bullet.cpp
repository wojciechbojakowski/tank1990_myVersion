#include "Bullet.h"

Bullet::Bullet(float x, float y)//dodać kierunek co pozwoli strzelać w róźnych kierunkach
{
    shape.setRadius(5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    alive = true;
    directX = 0;
    directY = 1;
}

Bullet::Bullet(float x, float y, float dx, float dy){
    shape.setRadius(5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    alive = true;
    this->directX = dx;
    this->directY = dy;
}

void Bullet::update(float dt)
{
    shape.move(-10*17*dt*directX, -10*17*dt*directY);
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