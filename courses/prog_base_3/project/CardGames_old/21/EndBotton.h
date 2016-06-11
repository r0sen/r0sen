#include <SFML/Graphics.hpp>

class EndBotton{
public:
    bool isPressed(float x, float y);
    EndBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


