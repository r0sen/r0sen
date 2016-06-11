#include <SFML/Graphics.hpp>

class NextRoundBottonSeka{
public:
    bool isPressed(float x, float y);
    NextRoundBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


