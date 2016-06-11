#include <SFML/Graphics.hpp>

class RestartBottonSeka{
public:
    bool isPressed(float x, float y);
    RestartBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};

