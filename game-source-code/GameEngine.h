#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "string"

#include "Player.h"
#include "GameEngine.h"
#include <memory>
#include "Bullet.h"
#include "Enemies.h"
#include "EnemyBullet.h"
#include "MiniMap.h"
#include "InputHandler.h"
#include "GameConfig.h"
#include "Fuel.h"

using namespace std;
using namespace sf;

class Game
{

public:
    GameConfig gameConfig;     // Declare first since other members depend on it
    Player Play;               // Declare Player object after GameConfig
    InputHandler inputHandler; // Declare InputHandler after Player
    void generateFuel();
    Game();
    Game(const GameConfig &config);
    ~Game();

    const bool isPlaying();
    void pollEvent();
    void update();
    void render();

    // FUNCTIONS declared for UNIT TESTING purposes
    Event getEvent() { return event; }
    bool getEndGame() { return endGame; }
    bool areSpritesColliding(const sf::Sprite &sprite1, const sf::Sprite &sprite2);

    void isGameOver();

    void initWindow(const GameConfig &config);
    string results = "none";
    RenderWindow *window;

private:
    VideoMode videoMode;
    bool endGame;
    Event event;
    Texture backgroundTexture; // Added for background
    Sprite backgroundSprite;
      sf::Texture mainBackgroundTexture;
    sf::Sprite mainBackgroundSprite;
    MiniMap minimap;
    sf::RectangleShape fuelBar;
    sf::RectangleShape fuelBorder;
    sf::Clock enemySpawnClock;  // Clock to measure time since the last enemy spawn
float enemySpawnTime = 1.0f;
    int fuelCount = 100;
    bool fell = false;

    void initVariables();

    void initWorld();

    vector<shared_ptr<Bullet>> bullets;
    vector<shared_ptr<Enemy>> enemies;
    vector<shared_ptr<Enemy_bullet>> enemy_bullets;
    vector<shared_ptr<Fuel>> _fuel;
    int count = 0;
    int total_fuel = 5;
};
#endif
