#ifndef BULLET
#define BULLET

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class Bullet
{
public:
    Bullet(float initialX, float initialY, string travelDirection);
    sf::Sprite& getSprite();
    void move();
    bool isVisible() const;
    void removeFromScreen();

private:
    string travelDirection;
    sf::Texture Texture;
    sf::Sprite Sprite;
    bool visible = true;
};

#endif 
