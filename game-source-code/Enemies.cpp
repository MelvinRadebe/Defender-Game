#include "Enemies.h"
#include "GameConfig.h"

Enemy::Enemy()
{
    // Load the bullet's texture (you may add your own texture loading logic here)
    if (!Texture.loadFromFile("resources/alien.png"))
    {
        // Handle texture loading failure here
        std::cerr << "Error loading Enemy texture" << std::endl;
    }

    GameConfig gameConfig;

    // Get the enemy size from the GameConfig object
    float enemySize = gameConfig.getEnemySize();

    // Set the texture for the bullet sprite
    Sprite.setTexture(Texture);
    Sprite.setScale(enemySize, enemySize);
    // Set the initial position of the bullet sprite
    auto initialX = rand() % 700;
    auto initialY = rand() % 400;
    Sprite.setPosition(initialX, initialY);

    travelDirection = "";
    switchDirection();
}

sf::Sprite &Enemy::getSprite()
{
    return Sprite;
}

void Enemy::move()
{
    if (steps == 150)
    {
        switchDirection();
        steps = 0;
    }
    steps++;
    if (travelDirection == "right")
    {
        if (Sprite.getPosition().x > 670)
        {
            switchDirection();
            return;
        }
        Sprite.move(1.0f, 0.f);
        return;
    }
    if (travelDirection == "left")
    {
        if (Sprite.getPosition().x <= 0)
        {
            switchDirection();
            return;
        }
        Sprite.move(-1.0f, 0.f);
        return;
    }
    if (travelDirection == "up")
    {
        if (Sprite.getPosition().y <= 0)
        {
            switchDirection();
            return;
        }
        Sprite.move(0.0f, -1.0f);
        return;
    }
    if (travelDirection == "dow")
    {
        if (Sprite.getPosition().y > 380)
        {
            switchDirection();
            return;
        }
        Sprite.move(0.0f, 1.0f);
        return;
    }
}

void Enemy::switchDirection()
{
    while (true)
    {
        auto direction = rand() % 4 + 1;
        if (direction == 1 && travelDirection != "left")
        {
            travelDirection = "left";
            return;
        }
        else if (direction == 2 && travelDirection != "right")
        {
            travelDirection = "right";
            return;
        }
        else if (direction == 3 && travelDirection != "up")
        {
            travelDirection = "up";
            return;
        }
        else if (direction == 4 && travelDirection != "dow")
        {
            travelDirection = "dow";
            return;
        }
    }
}

bool Enemy::isVisible() const
{
    return visible;
}

void Enemy::removeFromScreen()
{
    visible = false;
}

GameConfig gameConfig;

// Get the enemy size from the GameConfig object
float enemySize = gameConfig.getEnemySize();