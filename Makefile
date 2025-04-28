# Makefile for Nuclear Reactor Simulation

# Kompilator
CXX = g++
# Flagi kompilatora (dodaj -pthread do wielowątkowości)
CXXFLAGS = -std=c++17 -Wall -pthread
# Flagi dla bibliotek SFML
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Pliki źródłowe
SRC = src/main.cpp src/Tank.cpp src/Wall.cpp src/Bullet.cpp src/Map.cpp src/Enemy.cpp

# Nazwa pliku wynikowego
OUT = tank1990

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(SFMLFLAGS)

# Czyszczenie plików wygenerowanych
clean:
	rm -f $(OUT)
