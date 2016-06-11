#include <SFML/Graphics.hpp>

class NextBottonSeka{
public:
    bool isPressed(float x, float y);
    NextBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};
