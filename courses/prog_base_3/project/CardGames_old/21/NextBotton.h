#include <SFML/Graphics.hpp>

class NextBotton{
public:
    bool isPressed(float x, float y);
    NextBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};
