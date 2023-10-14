
#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

class Collision {
public:
    bool areSpritesColliding(const sf::Sprite &sprite1, const sf::Sprite &sprite2);
};

#endif