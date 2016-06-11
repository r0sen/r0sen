#include <SFML/Graphics.hpp>

class ThirdGameBotton{
public:
    bool isPressed(float x, float y);
    ThirdGameBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


