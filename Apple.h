#pragma once
#include <SFML/Graphics.hpp>

class Apple {
public:
    Apple(sf::Vector2f position);
    void update(sf::Time dt);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float fallSpeed;
};
