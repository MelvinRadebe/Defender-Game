#ifndef ENEMY_BULLET
#define ENEMY_BULLET

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class Enemy_bullet
{
public:
    Enemy_bullet(float initialX, float initialY, float targetX, float targetY);
    sf::Sprite &getSprite();
    void move();
    bool isVisible() const;
    void removeFromScreen();

private:
    sf::Texture Texture;
    sf::Sprite Sprite;
    bool visible = true;
    float angle;
};

#endif
