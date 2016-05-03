#include <SFML/Graphics.hpp>

class RestartBotton{
public:
    bool isPressed(float x, float y);
    RestartBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};

