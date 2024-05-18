#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {

        font.loadFromFile("louj.otf");

        // Add title
        menu[0].setFont(font);
        menu[0].setCharacterSize(120);
        menu[0].setString("Skyfall");
        menu[0].setFillColor(sf::Color::White);
        menu[0].setStyle(sf::Text::Bold);
        menu[0].setPosition(sf::Vector2f(width / 2 - 230, height / 4-20));

        // Set up menu options
        menu[1].setFont(font);
        menu[1].setFillColor(sf::Color::White);
        menu[1].setCharacterSize(80);
        menu[1].setString("Start Game");
        menu[1].setPosition(sf::Vector2f(width / 2 - 100, height / 4+180));

        menu[2].setFont(font);
        menu[2].setFillColor(sf::Color::White);
        menu[2].setCharacterSize(80);
        menu[2].setString("Exit");
        menu[2].setPosition(sf::Vector2f(width / 2+160, height / 4 + 300));


       


    selected = 0;
    if (!bgTexture.loadFromFile("hh.jpg")) {
        std::cout << "Error loading background texture!" << std::endl;
    }
    bgSprite.setTexture(bgTexture);
    sf::Sprite backgroundSprite(bgTexture);

    float scrollSpeed = 100.0f; // Adjust the scroll speed
    sf::Clock clock;
}

Menu::~Menu() {}
void Menu::setSelected(int n) {
    selected = n;
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(bgSprite);
    for (int i = 0; i < 3; ++i) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
   
    if (selected > 0) {
        menu[selected].setFillColor(sf::Color{ 128, 0, 128 });
        selected--;
        menu[selected].setFillColor(sf::Color{128, 0, 128});
    }
    
}

void Menu::Movedown() {
    if (selected < 2) {
        menu[selected].setFillColor(sf::Color{ 128, 0, 128 });
        selected++;
        menu[selected].setFillColor(sf::Color{ 128, 0, 128 });
    }
   
}



