#include <SFML/Graphics.hpp>

class PassBotton{
public:
    bool isPressed(float x, float y);
    PassBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


