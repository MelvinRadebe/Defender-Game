#include "EnemyBullet.h"

Enemy_bullet::Enemy_bullet(float initialX, float initialY, float targetX, float targetY)
    : visible(true)
{
    // Load the bullet's texture (you may add your own texture loading logic here)
    if (!Texture.loadFromFile("resources/enemy_bullet.png"))
    {
        // Handle texture loading failure here
        std::cerr << "Error loading bullet texture" << std::endl;
    }

    // Calculate range and height
    auto range = targetX - initialX;
    auto height = targetY - initialY;

    // Calculate launch angle (in radians)
    angle = atan2f(height, range);
    // Set the texture for the bullet sprite
    Sprite.setTexture(Texture);
    Sprite.setScale(0.02, 0.02);
    // Set the initial position of the bullet sprite
    Sprite.setPosition(initialX, initialY);
}

sf::Sprite &Enemy_bullet::getSprite()
{
    return Sprite;
}

void Enemy_bullet::move()
{
    // Implement the logic to move the bullet here
    Sprite.move(1.0f * cosf(angle), 1.0f * sinf(angle));
}

bool Enemy_bullet::isVisible() const
{
    return visible;
}

void Enemy_bullet::removeFromScreen()
{
    visible = false;
    // Optionally, you can remove the bullet from the screen here
}
