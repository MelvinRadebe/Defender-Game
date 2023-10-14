#pragma once

#include <string>

class GameConfig
{
public:
    GameConfig();
    int getWindowWidth() const;
    int getWindowHeight() const;
    std::string getWindowTitle() const;
    int getFrameRateLimit() const;
    std::string getBackgroundTexturePath() const;
    int getInitialEnemyCount() const;
    int getInitialCountValue() const;
    int getCountThreshold() const;
    float getPlayerSpeed() const; // Add this line
    float getPlayerSize() const;  // Add this line
    float getEnemySpeed() const;  // Add this line
    float getEnemySize() const;   // Add this line

private:
    int windowWidth;
    int windowHeight;
    std::string windowTitle;
    int frameRateLimit;
    std::string backgroundTexturePath;
    int initialEnemyCount;
    int initialCountValue;
    int countThreshold;
    float playerSpeed; // Add this line
    float playerSize;  // Add this
    float enemySpeed;  // Add this line
    float enemySize;   // Add this line
};
