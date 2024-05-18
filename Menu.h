#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Menu
{
private:
    int selected;
    Font font;
    sf::Sprite bgSprite;
    sf::Texture bgTexture;
public:
    Text menu[3];
    Menu(float width, float height);
    void draw(RenderWindow& window);
    void MoveUp();
    void Movedown();
    void setSelected(int n);
    sf::Text title;
    int pressed()
    {
        return selected;
    }
    ~Menu();




};

