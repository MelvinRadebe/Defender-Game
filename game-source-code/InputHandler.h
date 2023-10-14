#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

#include "Bullet.h"
#include "Player.h"

using namespace sf;

class InputHandler
{
public:
    void handleInput(Player &player, std::vector<std::shared_ptr<Bullet>> &bullets, sf::RenderWindow &window);

private:

                              // ...
};

#endif // INPUTHANDLER_H
