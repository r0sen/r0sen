#include <SFML/Graphics.hpp>

class SecondGameBotton{
public:
    bool isPressed(float x, float y);
    SecondGameBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


