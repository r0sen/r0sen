#include <SFML/Graphics.hpp>

class RevealBotton{
public:
    bool isPressed(float x, float y);
    RevealBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


