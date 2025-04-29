#include "Map.h"

Map::Map(bool flag=false)
{
    // Przygotuj różne typy ścian
    brick.setSize(sf::Vector2f(40, 40));
    brick.setFillColor(sf::Color(150, 75, 0)); // cegła

    steel.setSize(sf::Vector2f(40, 40));
    steel.setFillColor(sf::Color(192, 192, 192)); // stal

    water.setSize(sf::Vector2f(40, 40));
    water.setFillColor(sf::Color(0, 0, 255)); // woda

    grass.setSize(sf::Vector2f(40, 40));
    grass.setFillColor(sf::Color(0, 255, 0)); // trawa

    base.setSize(sf::Vector2f(40, 40));
    base.setFillColor(sf::Color(255, 0, 0)); // baza (home)

    // Definiowanie siatki mapy: 20x15
    if(flag){
        this->generate();
    }else{
        tiles = {
            {0,0,1,1,1,0,0,2,2,0,0,1,1,1,0,0,1,1,1,0},
            {0,0,1,0,1,0,0,2,2,0,0,1,0,1,0,0,1,0,1,0},
            {1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,0,1,1,1},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {3,3,0,0,0,3,3,0,0,0,3,3,0,0,0,3,3,0,0,0},
            {3,3,0,0,0,3,3,0,0,0,3,3,0,0,0,3,3,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {4,4,0,4,4,0,4,4,0,4,4,0,4,4,0,4,4,0,4,4},
            {4,4,0,4,4,0,4,4,0,4,4,0,4,4,0,4,4,0,4,4},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1},
            {1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1},
            {0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0}
        };
    }
}

void Map::draw(sf::RenderWindow &window)
{
    for (size_t y = 0; y < tiles.size(); ++y)
    {
        for (size_t x = 0; x < tiles[y].size(); ++x)
        {
            sf::RectangleShape *shape = nullptr;
            switch (tiles[y][x])
            {
                case 1: shape = &brick; break;
                case 2: shape = &steel; break;
                case 3: shape = &water; break;
                case 4: shape = &grass; break;
                case 5: shape = &base; break;
            }

            if (shape)
            {
                shape->setPosition(x * 40, y * 40);
                window.draw(*shape);
            }
        }
    }
}

int Map::getTile(int x, int y) const
{
    if (y < 0 || y >= (int)tiles.size() || x < 0 || x >= (int)tiles[y].size())
        return 0;
    return tiles[y][x];
}

void Map::generate()
{
    srand(time(0));  // Zainicjalizuj losowanie

    // Stwórz mapę z losowymi typami kafelków
    tiles.resize(15, std::vector<int>(20, 0)); // 15x20 kafli

    for (int y = 0; y < 15; ++y)
    {
        for (int x = 0; x < 20; ++x)
        {
            int randType = rand() % 5; // Losowanie typu ściany

            if (randType == 0)
                tiles[y][x] = 0;  // Pusta przestrzeń
            else if (randType == 1)
                tiles[y][x] = 1;  // Cegła
            else if (randType == 2)
                tiles[y][x] = 2;  // Stal
            else if (randType == 3)
                tiles[y][x] = 3;  // Woda
            else
                tiles[y][x] = 4;  // Trawa
        }
    }
}

void Map::generateWalls(std::list<Wall>& walls)
{
    // Wykorzystaj mapę do generowania ścian w grze
    for (int y = 0; y < 15; ++y)
    {
        for (int x = 0; x < 20; ++x)
        {
            int tileType = tiles[y][x];
            if (tileType == 1)  // Cegła
                walls.emplace_back(x * 40, y * 40, Wall::Type::Brick);
            else if (tileType == 2)  // Stal
                walls.emplace_back(x * 40, y * 40, Wall::Type::Steel);
            else if (tileType == 3)  // Woda
                walls.emplace_back(x * 40, y * 40, Wall::Type::Water);
        }
    }
}
