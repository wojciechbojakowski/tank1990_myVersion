#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "Wall.h"

class Map
{
public:
    Map(bool flag);
    void draw(sf::RenderWindow &window);
    int getTile(int x, int y) const;
    void generate();
    void generateWalls(std::list<Wall>& walls);
private:
    std::vector<std::vector<int>> tiles;
    sf::RectangleShape brick, steel, water, grass, base;
};
