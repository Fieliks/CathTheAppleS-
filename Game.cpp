#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game()
    : window(sf::VideoMode(800, 600), "Catch the Apples"), basket(), score(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time dt) {
    basket.update(dt);

    if (spawnClock.getElapsedTime().asSeconds() > 1.0f) {
        spawnApple();
        spawnClock.restart();
    }

    for (auto& apple : apples)
        apple.update(dt);

    checkCatch();
}

void Game::render() {
    window.clear();
    basket.draw(window);
    for (auto& apple : apples)
        apple.draw(window);

    window.display();
}

void Game::spawnApple() {
    float x = static_cast<float>(std::rand() % 750); // screen width - apple size
    apples.emplace_back(sf::Vector2f(x, -50));
}

void Game::checkCatch() {
    for (auto it = apples.begin(); it != apples.end();) {
        if (it->getBounds().intersects(basket.getBounds())) {
            it = apples.erase(it);
            score++;
        }
        else if (it->getPosition().y > 600) {
            it = apples.erase(it); // missed
        }
        else {
            ++it;
        }
    }
}
