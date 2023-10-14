#include "Fuel.h"

Fuel::Fuel(vector<int> pos)
    : visible(true)
{
    // Load the bullet's texture (you may add your own texture loading logic here)
    if (!Texture.loadFromFile("resources/fuel.png"))
    {
        // Handle texture loading failure here
        std::cerr << "Error loading fuel texture" << std::endl;
    }

    // Set the texture for the bullet sprite
    Sprite.setTexture(Texture);
    Sprite.setScale(0.025, 0.025);
    // Set the initial position of the bullet sprite
    Sprite.setPosition(pos[0], pos[1]);
}

sf::Sprite &Fuel::getSprite()
{
    return Sprite;
}

bool Fuel::isVisible() const
{
    return visible;
}

void Fuel::removeFromScreen()
{
    visible = false;
}
