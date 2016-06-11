#include <SFML/Graphics.hpp>

class NextRoundBotton{
public:
    bool isPressed(float x, float y);
    NextRoundBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


