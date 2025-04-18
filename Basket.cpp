#include "Basket.h"

Basket::Basket() : speed(300.0f) {
    texture.loadFromFile("Assets/basket.png");
    sprite.setTexture(texture);
    sprite.setPosition(400, 550);
}

void Basket::update(sf::Time dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.move(-speed * dt.asSeconds(), 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.move(speed * dt.asSeconds(), 0);

    // Clamp to screen
    if (sprite.getPosition().x < 0)
        sprite.setPosition(0, sprite.getPosition().y);
    if (sprite.getPosition().x > 800 - sprite.getGlobalBounds().width)
        sprite.setPosition(800 - sprite.getGlobalBounds().width, sprite.getPosition().y);
}

void Basket::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Basket::getBounds() const {
    return sprite.getGlobalBounds();
}
