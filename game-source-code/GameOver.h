#pragma once

#include <vector>
#include <memory>
#include "Collisions.h"
#include "GameEngine.h" // Assumes this file contains the definition for the window object
#include "Player.h"     // Assumes this file contains the definition for the Player class
#include "Enemies.h"      // You need to include Enemy.h as you are using Enemy objects in your class
#include "Bullet.h"     // You need to include Bullet.h as you are using Bullet objects in your class
#include "GameStateManager.h"
class Game
{
public:
    void isGameOver(std::shared_ptr<GameStateManager> manager); // Declaration of the isGameOver method


private:
    Player Play;                                        // Assumes Player class is defined in Player.h
    std::shared_ptr<GameEngine::WindowType> window;     // Replace GameEngine::WindowType with the actual type of your window object
    std::vector<std::shared_ptr<Enemy>> enemies;        // Vector of shared pointers to Enemy objects
    std::vector<std::shared_ptr<Bullet>> bullets;       // Vector of shared pointers to Bullet objects
    std::vector<std::shared_ptr<Bullet>> enemy_bullets; // Vector of shared pointers to Bullet objects for enemy bullets
    std::shared_ptr<GameStateManager> manager;
};
