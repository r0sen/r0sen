#include <SFML/Graphics.hpp>

class RepeatBottonSeka{
public:
    bool isPressed(float x, float y);
    RepeatBottonSeka();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    float posX;
    float posY;
    float width;
    float height;
};


