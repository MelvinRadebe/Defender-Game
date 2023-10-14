#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

using namespace std;

class Fuel
{
public:
    Fuel(vector<int> pos);
    sf::Sprite &getSprite();
    bool isVisible() const;
    void removeFromScreen();

private:
    sf::Texture Texture;
    sf::Sprite Sprite;
    bool visible = true;
};