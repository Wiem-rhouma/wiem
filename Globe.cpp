#include "Globe.h"

Globe::Globe(sf::Texture* texture, float x, float y, float speed, float scale, GlobeType type) : speed(speed), type(type) {
    globeSprite.setTexture(*texture);
    globeSprite.setScale(scale, scale);
    globeSprite.setPosition(x, y);
}

void Globe::update(float deltaTime) {
    globeSprite.move(0, speed * deltaTime);
    if (globeSprite.getPosition().y > 800) {
        globeSprite.setPosition(globeSprite.getPosition().x, -globeSprite.getGlobalBounds().height);
    }
}

void Globe::draw(sf::RenderWindow& window) {
    window.draw(globeSprite);
}

bool Globe::checkCollision(const sf::FloatRect& playerBounds) const {
    return globeSprite.getGlobalBounds().intersects(playerBounds);
}

sf::FloatRect Globe::getGlobeBounds() const {
    return globeSprite.getGlobalBounds();
}

GlobeType Globe::getType() const {
    return type;
}