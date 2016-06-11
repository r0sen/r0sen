#include <SFML/Graphics.hpp>

class FourthGameBotton{
public:
    bool isPressed(float x, float y);
    FourthGameBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


