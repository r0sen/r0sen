#include <SFML/Graphics.hpp>

class FifthGameBotton{
public:
    bool isPressed(float x, float y);
    FifthGameBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


