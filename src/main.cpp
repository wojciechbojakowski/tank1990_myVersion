#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Bullet.h"
#include "Wall.h"
#include <list>
#include <vector>
#include "Map.h"
#include "Enemy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tank 1990 DIY Version");
    std::list<Wall> walls;

    // // Przygotuj kilka ścian (możesz tu później zrobić generator mapy)
    // walls.emplace_back(300, 300);
    // walls.emplace_back(340, 300);
    // walls.emplace_back(380, 300);

    Tank playerTank(400, 500);
    Map gameMap(false);

    gameMap.generateWalls(walls);

    std::vector<Enemy> enemies;
    enemies.emplace_back(100, 100);
    enemies.emplace_back(600, 100);

    std::vector<Bullet> bullets;

    sf::Clock clock;

    while (window.isOpen())
    {
        static sf::Clock deltaClock;
        float dt = deltaClock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            playerTank.move(-1, 0, walls,dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            playerTank.move(1, 0, walls,dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            playerTank.move(0, -1, walls,dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            playerTank.move(0, 1, walls,dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (clock.getElapsedTime().asMilliseconds() > 300) { // cooldown
                bullets.push_back(playerTank.shoot());
                clock.restart();
            }
        }

        // Update bullets
        for (auto &bullet : bullets)
        {
            bullet.update(dt);
            for (auto &wall : walls)
            {
                if (bullet.getShape().getGlobalBounds().intersects(wall.getShape().getGlobalBounds()))
                {
                    bullet.kill(); // zabij pocisk
                }
            }
        }

        for (auto &enemy : enemies)
            enemy.update(dt,walls);

        // Remove bullets out of screen
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
            [](Bullet &b) { return !b.isAlive(); }), bullets.end());

        // Render
        window.clear();

        gameMap.draw(window);

        for (auto &enemy : enemies)
            enemy.draw(window);


        playerTank.draw(window);

        for (auto &bullet : bullets)
            bullet.draw(window);

        window.display();
    }

    return 0;
}
