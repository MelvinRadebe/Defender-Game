#ifndef ENEMY
#define ENEMY

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Enemy
{
public:
    Enemy();
    sf::Sprite &getSprite();
    void move();
    void switchDirection();
    bool isVisible() const;
    void removeFromScreen();

private:
    string travelDirection;
    sf::Texture Texture;
    sf::Sprite Sprite;
    bool visible = true;
    int steps = 0;
};

#endif
