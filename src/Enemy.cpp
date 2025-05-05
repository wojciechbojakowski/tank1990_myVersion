#include "Enemy.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy(float x, float y)
{
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);
    this->alive=true;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    direction = sf::Vector2f(0, 1); // start w dół
}

void Enemy::update(float dt,  std::list<Wall> &walls)
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
            // ech mnożenie wektorów do zrobienia
            shape.move(-direction * 80.f * dt);
            break;
        }
    }
}

void Enemy::kill(){
    this->alive=false;
}

bool Enemy::isAlive(){
    return this->alive;
}

void Enemy::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::RectangleShape &Enemy::getShape()
{
    return shape;
}
