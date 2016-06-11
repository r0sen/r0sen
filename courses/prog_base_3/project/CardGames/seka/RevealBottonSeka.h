#include <SFML/Graphics.hpp>

class RevealBottonSeka{
public:
    bool isPressed(float x, float y);
    RevealBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


