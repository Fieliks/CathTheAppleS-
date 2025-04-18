#include "Apple.h"

Apple::Apple(sf::Vector2f position) : fallSpeed(200.0f) {
    texture.loadFromFile("Assets/apple.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Apple::update(sf::Time dt) {
    sprite.move(0, fallSpeed * dt.asSeconds());
}

void Apple::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Apple::getBounds() const {
    return sprite.getGlobalBounds();
}

sf::Vector2f Apple::getPosition() const {
    return sprite.getPosition();
}
