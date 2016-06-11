#include <SFML/Graphics.hpp>

class FirstGameBotton{
public:
    bool isPressed(float x, float y);
    FirstGameBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


