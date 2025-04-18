#pragma once
#include <SFML/Graphics.hpp>

class Basket {
public:
    Basket();
    void update(sf::Time dt);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
};
