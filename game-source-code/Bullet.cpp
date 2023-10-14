#include "Bullet.h"

Bullet::Bullet(float initialX, float initialY, string travelDirection)
    : travelDirection(travelDirection), visible(true)
{
    // Load the bullet's texture (you may add your own texture loading logic here)
    if (!Texture.loadFromFile("resources/bullet.png"))
    {
        // Handle texture loading failure here
        std::cerr << "Error loading bullet texture" << std::endl;
    }

    // Set the texture for the bullet sprite
    Sprite.setTexture(Texture);
    Sprite.setScale(0.06, 0.02);
    Sprite.rotate(90);
    // Set the initial position of the bullet sprite
    Sprite.setPosition(initialX, initialY + 10);
}

sf::Sprite &Bullet::getSprite()
{
    return Sprite;
}

void Bullet::move()
{
    // Implement the logic to move the bullet here
    if (travelDirection == "right")
    {
        Sprite.move(2, 0.f);
    }
    else
    {
        Sprite.move(-2, 0.f);
    }
}

bool Bullet::isVisible() const
{
    return visible;
}

void Bullet::removeFromScreen()
{
    visible = false;
}
