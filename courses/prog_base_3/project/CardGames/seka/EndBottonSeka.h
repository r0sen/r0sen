#include <SFML/Graphics.hpp>

class EndBottonSeka{
public:
    bool isPressed(float x, float y);
    EndBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


