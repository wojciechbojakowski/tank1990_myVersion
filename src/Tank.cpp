#include "Tank.h"
#include <cmath>
#include <iostream>

Tank::Tank(float x, float y)
{
    shape.setSize(sf::Vector2f(20, 20));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
}

void Tank::move(float dx, float dy)
{
    shape.move(dx * 5, dy * 5);
}

void Tank::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

Bullet Tank::shoot()
{
    sf::Vector2f pos = shape.getPosition();
    return Bullet(pos.x + shape.getSize().x / 2 - 5, pos.y);
}

Bullet Tank::shootWithMouse(float dx, float dy){
    sf::Vector2f pos = shape.getPosition();
    // Oblicz wektor od czołgu do pozycji myszy
    float dirX = -(dx - pos.x);
    float dirY = -(dy - pos.y);

    // Znormalizuj ten wektor (czyli kierunek strzału)
    float length = std::sqrt(dirX * dirX + dirY * dirY);
    float normX = dirX / length;
    float normY = dirY / length;

    std::cout << normX << ", " << normY <<" | "<<dx<<", "<<dy<<" | "<<pos.x<<", "<<pos.y<< std::endl;

    // Tworzenie pocisku na środku czołgu z kierunkiem lotu
    return Bullet(pos.x + shape.getSize().x / 2 - 5, pos.y, normX, normY);
}

void Tank::move(float dx, float dy, std::list<Wall> &walls, float dt)
{
    shape.move(dx * 150.f*dt, dy * 150.f*dt);

    sf::Vector2f pos = shape.getPosition();
    
    if (pos.x < 0) shape.setPosition(0, pos.y);
    if (pos.y < 0) shape.setPosition(pos.x, 0);
    if (pos.x + shape.getSize().x > 800) shape.setPosition(800 - shape.getSize().x, pos.y);
    if (pos.y + shape.getSize().y > 600) shape.setPosition(pos.x, 600 - shape.getSize().y);

    for (Wall &wall : walls)
    {
        if (shape.getGlobalBounds().intersects(wall.getShape().getGlobalBounds()))
        {
            // Cofnij ruch w przypadku kolizji
            shape.move(-dx * 150.f*dt, -dy *150.f*dt);
            break;
        }
    }
}