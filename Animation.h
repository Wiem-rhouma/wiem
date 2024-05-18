
#pragma once
#include<SFML/Graphics.hpp>

	class Animation
	{
	private:

		float elapsedTime;

		float switchingTime;

		sf::Vector2u totalImages;

		sf::Vector2u currentImagePosition;
	public:

		sf::IntRect uvRect;

		Animation(sf::Texture* texture, sf::Vector2u totalImages, float switchingTime);

		void update(int rowNumber, float deltaTime, bool playerFacingRight);
	};


