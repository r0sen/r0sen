#include <SFML/Graphics.hpp>

class PassBottonSeka{
public:
    bool isPressed(float x, float y);
    PassBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


