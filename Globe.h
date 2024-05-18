#include <SFML/Graphics.hpp>

enum GlobeType {
    PLANET_1,
    PLANET_2,
    PLANET_3
};

class Globe {
public:
    Globe(sf::Texture* texture, float x, float y, float speed, float scale, GlobeType type);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool checkCollision(const sf::FloatRect& playerBounds) const;
    sf::FloatRect getGlobeBounds() const;
    GlobeType getType() const;

    // Method to get the speed
    float getSpeed() const;

    // Method to set the speed
    void setSpeed(float newSpeed);

private:
    sf::Sprite globeSprite;
    float speed;
    GlobeType type;
};
