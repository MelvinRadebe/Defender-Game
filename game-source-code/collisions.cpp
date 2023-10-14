#include "Collisions.h"

bool Collision::areSpritesColliding(const sf::Sprite &sprite1, const sf::Sprite &sprite2)
{
    // Get the global bounding boxes of the sprites
    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();

    // Define four points within the first sprite for collision detection
    sf::Vector2f topLeft = sprite1.getPosition();
    sf::Vector2f topRight = sprite1.getPosition() + sf::Vector2f(bounds1.width, 0);
    sf::Vector2f bottomLeft = sprite1.getPosition() + sf::Vector2f(0, bounds1.height);
    sf::Vector2f bottomRight = sprite1.getPosition() + sf::Vector2f(bounds1.width, bounds1.height);

    // Check if any of the points are within the bounds of the second sprite
    if (bounds2.contains(topLeft) || bounds2.contains(topRight) ||
        bounds2.contains(bottomLeft) || bounds2.contains(bottomRight))
    {
        return true;
    }

    // No collision detected
    return false;
}