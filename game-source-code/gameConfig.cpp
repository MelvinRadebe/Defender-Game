#include "GameConfig.h"

GameConfig::GameConfig()
    : windowWidth(700),
      windowHeight(400),

      frameRateLimit(60),
      backgroundTexturePath("resources/BG.jpg"),
      initialEnemyCount(10),
      initialCountValue(0),
      countThreshold(150),
      playerSpeed(4.f),  // initialize playerSpeed here
      playerSize(0.04f), // initialize playerSize here

      enemySpeed(5.f), // initialize playerSpeed here
      enemySize(0.01f) // initialize playerSize here                  //enemey speed
                       // enemy player size
{
}

int GameConfig::getWindowWidth() const { return windowWidth; }
int GameConfig::getWindowHeight() const { return windowHeight; }
std::string GameConfig::getWindowTitle() const { return windowTitle; }
int GameConfig::getFrameRateLimit() const { return frameRateLimit; }
std::string GameConfig::getBackgroundTexturePath() const { return backgroundTexturePath; }
int GameConfig::getInitialEnemyCount() const { return initialEnemyCount; }
int GameConfig::getInitialCountValue() const { return initialCountValue; }
int GameConfig::getCountThreshold() const { return countThreshold; }
float GameConfig::getPlayerSpeed() const { return playerSpeed; } // Add getter for playerSpeed
float GameConfig::getPlayerSize() const { return playerSize; }   // Add getter for playerSize
float GameConfig::getEnemySpeed() const { return enemySpeed; }   // Add getter for playerSpeed
float GameConfig::getEnemySize() const { return enemySize; }     // Add getter for playerSize