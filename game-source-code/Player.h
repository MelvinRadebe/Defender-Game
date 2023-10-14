#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// #include "game.h"

using namespace std;
using namespace sf;

class Player
{
private:
    float movespeed;
    std::string direction;
    std::string bullet_dir;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RectangleShape rectangle;
    bool move = false;

public:
    Player();

    void initVariables();
    void initShape();
    void setInputDirection(const std::string &newDirection); // New method to set input direction

    Vector2f getPosition() const { return sprite.getPosition(); }
    std::string getDirection() const;
    sf::Sprite &getSprite();

    void update(const sf::RenderTarget *target);
    void render(sf::RenderTarget *target);
    void drawBackground(sf::RenderTarget *target);
};

#endif
