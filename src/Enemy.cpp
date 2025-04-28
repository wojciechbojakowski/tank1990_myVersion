#include "Enemy.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy(float x, float y)
{
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    direction = sf::Vector2f(0, 1); // start w dół
}

void Enemy::update(float dt)
{
    shape.move(direction * 80.f * dt);

    // zmiana kierunku co pewien czas
    if (changeDirClock.getElapsedTime().asSeconds() > 2.f)
    {
        int dir = rand() % 4;
        switch (dir)
        {
            case 0: direction = sf::Vector2f(0, -1); break; // góra
            case 1: direction = sf::Vector2f(0, 1); break;  // dół
            case 2: direction = sf::Vector2f(-1, 0); break; // lewo
            case 3: direction = sf::Vector2f(1, 0); break;  // prawo
        }
        changeDirClock.restart();
    }
}

void Enemy::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::RectangleShape &Enemy::getShape()
{
    return shape;
}
