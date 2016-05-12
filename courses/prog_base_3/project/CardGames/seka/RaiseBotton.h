#include <SFML/Graphics.hpp>

class RaiseBotton{
public:
    bool isPressed(float x, float y);
    RaiseBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


