#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Basket.h"
#include "Apple.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time dt);
    void render();
    void spawnApple();
    void checkCatch();

    sf::RenderWindow window;
    Basket basket;
    std::vector<Apple> apples;
    sf::Clock spawnClock;
    int score;
};
