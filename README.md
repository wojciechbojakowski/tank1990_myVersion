# Tank 1990 DIY Version

**Tank 1990 DIY Version** is a simple clone of the classic game "Tank 1990," implemented in C++ using the SFML library. The game features tanks, enemies, various types of walls (brick, steel, water), and collision mechanics.

[Some text about Tank 1990 but in Polish](https://www.gry-online.pl/newsroom/w-te-czolgi-gralismy-do-upadlego-na-dlugo-przed-world-of-tanks-ta/zf2d4b3)


## Description

In this version of the game, you control a tank that moves around a map with randomly generated walls. The tank can shoot at enemies and collide with obstacles. The game features basic mechanics such as movement, shooting, and collisions.

### Features(not yet):
- **Player**: Control the tank, shoot projectiles.
- **Enemies**: Automatically moving enemies that try to destroy the player.
- **Map**: Randomly generated walls with collisions (brick, steel, water).
- **Collisions**: Projectiles can collide with different types of walls.

## Technologies

- C++
- SFML (Simple and Fast Multimedia Library)
- Standard C++ library

## How to Run

### Requirements:
- C++ compiler (e.g., GCC, MSVC)
- SFML 2.x installed on your system

### Installation and Running:

1. **Download SFML**:
   - You can download the SFML library from the official website: [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php).
   
2. **Copy Project Files**:
   - Copy the downloaded SFML files into the project folder.

3. **Compile**:
   - To compile the project, use your C++ compiler and set the appropriate flags to include the SFML library. For example, using g++:
   
     ```bash
     g++ -o tank_game main.cpp Map.cpp Tank.cpp Bullet.cpp Enemy.cpp Wall.cpp -lsfml-graphics -lsfml-window -lsfml-system
     ```

   Or you can use Makefile
   ```bash
   make
   ```

5. **Run**:
   - After compiling, run the game:
   
     ```bash
     ./tank_game
     ```

## Controls

- **Arrow Keys**: Move the tank.
- **Spacebar**: Shoot projectiles.

## Project Structure
/project 
|  /src
  ├── Map.cpp # Map generation and rendering 
  ├── Tank.cpp # Player tank class 
  ├── Bullet.cpp # Bullet class 
  ├── Enemy.cpp # Enemy class 
  ├── Wall.cpp # Wall class 
  ├── Map.h # Header for Map class 
  ├── Tank.h # Header for Tank class 
  ├── Bullet.h # Header for Bullet class 
  ├── Enemy.h # Header for Enemy class 
  ├── Wall.h # Header for Wall class 
├── main.cpp # Main game loop 
└── README.md # Project documentation (this file)


## Future Plans

- **Add new wall types**: Introduce more wall types, such as sand, rocks, etc.
- **More enemies**: Add different types of enemies with varying behaviors.
- **Animations**: Add animations for the tank and projectiles.
- **Multiplayer**: Implement a multiplayer mode.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

---
