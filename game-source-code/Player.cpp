
#include "Player.h"
#include "GameConfig.h"

Player::Player()
{
    this->rectangle.setPosition(350, 200);
    this->initVariables();
    this->initShape();

    // Load the background texture
}

void Player::initVariables()
{
    this->movespeed = 5.f;
    this->direction = "right";
}

void Player::initShape()
{
    if (!texture.loadFromFile("resources/F22.png"))
    {
        // Handle error loading the texture
        std::cerr << "Error loading player texture" << std::endl;
    }

    GameConfig game;
    float size = game.getPlayerSize();
    sprite.setTexture(texture);
    sprite.setScale(size, size); // Adjust the scale as needed
    sprite.rotate(90);
    sprite.setPosition(350, 200);

    if (!backgroundTexture.loadFromFile("resources/BG.jpg"))
    {
        std::cerr << "Could not load resource BG.png" << std::endl;
        // Handle the error as needed
    }
    backgroundSprite.setTexture(backgroundTexture);
    bullet_dir = "right";
}

void Player::setInputDirection(const std::string &newDirection)
{
    move = true;
    direction = newDirection;
}

std::string Player::getDirection() const
{
    return bullet_dir;
}

sf::Sprite &Player::getSprite()
{
    return sprite;
}

void Player::update(const sf::RenderTarget *target)
{
    // Set the origin of the sprite to its center
    if (move)
    {
        sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);

        // Get the size of the window
        sf::Vector2u windowSize = target->getSize();
        float boundaryOffset = 10.0f; // Adjust this to the desired distance in pixels
        auto position = sprite.getPosition();

        GameConfig game;
        float size = game.getPlayerSize();
        float speed = game.getPlayerSpeed();

        if (direction == "left" && sprite.getPosition().x > 0)
        {
            sprite.setScale(size, -size);
            sprite.setPosition(position);
            sprite.move(-speed, 0.f);
            bullet_dir = "left";
        }
        else if (direction == "right" && sprite.getPosition().x < windowSize.x)
        {
            sprite.setScale(size, size);
            sprite.setPosition(position);
            sprite.move(speed, 0.f);
            bullet_dir = "right";
        }

        if (direction == "up" && sprite.getPosition().y > 0)
        {
            sprite.move(0.f, -speed);
        }
        else if (direction == "dow" && sprite.getPosition().y + sprite.getGlobalBounds().height < windowSize.y)
        {
            sprite.move(0.f, movespeed);
        }
    }
    move = false;
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(sprite);
}

void Player::drawBackground(sf::RenderTarget *target)
{
    target->draw(backgroundSprite);
}