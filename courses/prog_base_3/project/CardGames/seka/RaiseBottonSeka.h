#include <SFML/Graphics.hpp>

class RaiseBottonSeka{
public:
    bool isPressed(float x, float y);
    RaiseBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


