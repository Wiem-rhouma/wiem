#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u totalImages, float switchingTime,float playerSpeed);
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape& getBody();
	sf::Vector2f getPlayerPosition();
	sf::Vector2f getPlayerVelocity();
private:
	sf::Vector2f velocity;
	sf::RectangleShape playerBody;
	Animation animation;
	unsigned int rowNumber;
	float playerSpeed;
	bool playerFacingRight;
    
};
