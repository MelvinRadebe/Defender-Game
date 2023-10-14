#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemies.h"
#include "EnemyBullet.h"
#include "GameEngine.h"
#include "Collisions.h"

TEST_CASE("Player Initialization Test")
{
    Player player;

    CHECK(player.getDirection() == "right"); // Check the default direction
    CHECK(player.getPosition().x == 350);
    CHECK(player.getPosition().y == 200);
}

TEST_CASE("Player Move Right Test")
{
    Player player;
    sf::Vector2f initialPosition = player.getSprite().getPosition();

    player.setInputDirection("right");
    auto window = new RenderWindow();
    window->create(VideoMode(700, 400), "demo", Style::Close | Style::Titlebar);
    player.update(window);

    CHECK(player.getDirection() == "right");
    CHECK(player.getSprite().getPosition().x > initialPosition.x); // Check if the player moved right
    delete window;
}

TEST_CASE("Player Move Left Test")
{
    Player player;
    sf::Vector2f initialPosition = player.getSprite().getPosition();

    player.setInputDirection("left");
    auto window = new RenderWindow();
    window->create(VideoMode(700, 400), "demo", Style::Close | Style::Titlebar);
    player.update(window);

    CHECK(player.getDirection() == "left");
    CHECK(player.getSprite().getPosition().x < initialPosition.x); // Check if the player moved left
    delete window;
}

TEST_CASE("Player Move Up Test")
{
    Player player;
    sf::Vector2f initialPosition = player.getSprite().getPosition();

    player.setInputDirection("up");
    auto window = new RenderWindow();
    window->create(VideoMode(700, 400), "demo", Style::Close | Style::Titlebar);
    player.update(window);

    CHECK(player.getSprite().getPosition().y < initialPosition.y); // Check if the player moved up
    delete window;
}

TEST_CASE("Player Move Down Test")
{
    Player player;
    sf::Vector2f initialPosition = player.getSprite().getPosition();

    player.setInputDirection("down");
    auto window = new RenderWindow();
    window->create(VideoMode(700, 400), "demo", Style::Close | Style::Titlebar);
    player.update(window);

    CHECK(player.getSprite().getPosition().y >= initialPosition.y); // Check if the player moved down
    delete window;
}

TEST_CASE("Bullet Initialization Test")
{
    Bullet bullet(100.f, 200.f, "right");

    CHECK(bullet.isVisible() == true);                  // Check if the bullet is initially visible
    CHECK(bullet.getSprite().getPosition().x == 100.f); // Check initial X position
    CHECK(bullet.getSprite().getPosition().y == 210.f); // Check initial Y position (adjusted for initialY + 10)
}

TEST_CASE("Bullet Movement Right Test")
{
    Bullet bullet(100.f, 200.f, "right");
    sf::Vector2f initialPosition = bullet.getSprite().getPosition();

    bullet.move();

    CHECK(bullet.isVisible() == true);                             // Check if the bullet is still visible after moving
    CHECK(bullet.getSprite().getPosition().x > initialPosition.x); // Check if the bullet moved right
}

TEST_CASE("Bullet Movement Left Test")
{
    Bullet bullet(100.f, 200.f, "left");
    sf::Vector2f initialPosition = bullet.getSprite().getPosition();

    bullet.move();

    CHECK(bullet.isVisible() == true);                             // Check if the bullet is still visible after moving
    CHECK(bullet.getSprite().getPosition().x < initialPosition.x); // Check if the bullet moved left
}

TEST_CASE("Bullet Visibility After Removal Test")
{
    Bullet bullet(100.f, 200.f, "right");

    bullet.removeFromScreen();

    CHECK(bullet.isVisible() == false); // Check if the bullet is not visible after removal
}

TEST_CASE("Enemy Initialization Test")
{
    Enemy enemy;

    CHECK(enemy.isVisible() == true); // Check if the enemy is initially visible
}

TEST_CASE("Enemy Visibility After Removal Test")
{
    Enemy enemy;

    enemy.removeFromScreen();

    CHECK(enemy.isVisible() == false); // Check if the enemy is not visible after removal
}

TEST_CASE("Enemy_bullet Initialization Test")
{
    Enemy_bullet enemyBullet(100.f, 200.f, 300.f, 250.f);

    CHECK(enemyBullet.isVisible() == true); // Check if the enemyBullet is initially visible
}

TEST_CASE("Enemy_bullet Movement Test")
{
    Enemy_bullet enemyBullet(100.f, 200.f, 300.f, 250.f);
    sf::Vector2f initialPosition = enemyBullet.getSprite().getPosition();

    enemyBullet.move();

    CHECK(enemyBullet.isVisible() == true);                          // Check if the enemyBullet is still visible after moving
    CHECK(enemyBullet.getSprite().getPosition() != initialPosition); // Check if the enemyBullet's position has changed
}

TEST_CASE("Enemy_bullet Visibility After Removal Test")
{
    Enemy_bullet enemyBullet(100.f, 200.f, 300.f, 250.f);

    enemyBullet.removeFromScreen();

    CHECK(enemyBullet.isVisible() == false); // Check if the enemyBullet is not visible after removal
}

TEST_CASE("Sprites Collision Test")
{
    Collision collision;
    // Create two sprites with known positions and sizes
    sf::Sprite sprite1;
    sprite1.setPosition(100.f, 100.f);
    sprite1.setTextureRect(sf::IntRect(0, 0, 50, 50)); // Assuming a size of 50x50

    sf::Sprite sprite2;
    sprite2.setPosition(120.f, 120.f);                 // Overlapping with sprite1
    sprite2.setTextureRect(sf::IntRect(0, 0, 50, 50)); // Assuming a size of 50x50

    // Check if the two sprites are colliding
    bool collisionResult = collision.areSpritesColliding(sprite1, sprite2);

    CHECK(collisionResult == true); // Expecting a collision
}

TEST_CASE("No Collision Test")
{
Collision collision;
    // Create two sprites with known positions and sizes that do not overlap
    sf::Sprite sprite1;
    sprite1.setPosition(100.f, 100.f);
    sprite1.setTextureRect(sf::IntRect(0, 0, 50, 50)); // Assuming a size of 50x50

    sf::Sprite sprite2;
    sprite2.setPosition(200.f, 200.f);                 // Not overlapping with sprite1
    sprite2.setTextureRect(sf::IntRect(0, 0, 50, 50)); // Assuming a size of 50x50

    // Check if the two sprites are colliding
    bool collisionResult = collision.areSpritesColliding(sprite1, sprite2);

    CHECK(collisionResult == false); // Expecting no collision
}
