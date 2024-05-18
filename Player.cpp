#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u totalImages, float switchingTime,
    float playerSpeed) : animation(texture, totalImages, switchingTime)
{
    this->playerSpeed = playerSpeed;
    rowNumber = 0;
    playerFacingRight = true;
    playerBody.setSize(sf::Vector2f(120.0f, 120.0f));
    playerBody.setPosition(640.0f, 500.0f);
    playerBody.setTexture(texture);
    velocity = sf::Vector2f(0.0f, 0.0f); // Initialize velocity
}

void Player::update(float deltaTime)
{
    // Get movement input
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= playerSpeed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += playerSpeed * deltaTime;

    // Update animation
    if (movement.x == 0.0f)
        rowNumber = 0;
    else
    {
        rowNumber = 0;
        if (movement.x > 0.0f)
            playerFacingRight = true;
        else
            playerFacingRight = false;
    }
    animation.update(rowNumber, deltaTime, playerFacingRight);

    // Update player position
    playerBody.setTextureRect(animation.uvRect);
    playerBody.move(movement);

    // Ensure player stays within window bounds
    sf::Vector2f position = playerBody.getPosition();
    if (position.x < 0)
        playerBody.setPosition(0, position.y);
    else if (position.x + playerBody.getSize().x > 1200)
        playerBody.setPosition(800 - playerBody.getSize().x, position.y);

    // Update velocity (if needed)
    velocity = movement;
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(playerBody);
}

sf::RectangleShape& Player::getBody()
{
    return playerBody;
}

sf::Vector2f Player::getPlayerPosition() {
    return playerBody.getPosition();
}

sf::Vector2f Player::getPlayerVelocity() {
    return velocity;
}