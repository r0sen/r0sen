#include <SFML/Graphics.hpp>

class RepeatBotton{
public:
    bool isPressed(float x, float y);
    RepeatBotton();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


