#include "InputHandler.h"
#include <iostream>
#include <set> // Include set to manage multiple keys

void InputHandler::handleInput(Player &player, std::vector<std::shared_ptr<Bullet>> &bullets, sf::RenderWindow &win)
{
    Event event;
    static std::set<Keyboard::Key> pressedKeys; // Keep track of pressed keys

    while (win.pollEvent(event))
    {
        if (Event::Closed == event.type)
        {
            win.close();
        }
        if (event.type == Event::KeyPressed)
        {
            pressedKeys.insert(event.key.code); // Add key to set when pressed
        }
        if (event.type == Event::KeyReleased)
        {
            pressedKeys.erase(event.key.code); // Remove key from set when released
        }
    }

    // Handle movements based on keys in the set
    if (pressedKeys.find(Keyboard::Left) != pressedKeys.end())
    {
        player.setInputDirection("left");
    }
    if (pressedKeys.find(Keyboard::Right) != pressedKeys.end())
    {
        player.setInputDirection("right");
    }
    if (pressedKeys.find(Keyboard::Up) != pressedKeys.end())
    {
        player.setInputDirection("up");
    }
    if (pressedKeys.find(Keyboard::Down) != pressedKeys.end())
    {
        player.setInputDirection("dow");
    }
    if (pressedKeys.find(Keyboard::Space) != pressedKeys.end())
    {
        bullets.push_back(std::make_shared<Bullet>(player.getPosition().x, player.getPosition().y, player.getDirection()));
        pressedKeys.erase(Keyboard::Space); // Optional: prevent continuous shooting
    }
}
