
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "MiniMap.h"

MiniMap::MiniMap()
{
    // initialize your minimap view here
    miniMapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));
    miniMapView.setSize(700, 400);           // Set the size of the minimap view
    miniMapView.setCenter(700 / 2, 400 / 2); // Center the minimap view

    minimapBorder.setSize(sf::Vector2f(1600, 370)); // Set size as per your requirements
    minimapBorder.setOutlineColor(sf::Color::White);
    minimapBorder.setOutlineThickness(10);
    minimapBorder.setFillColor(sf::Color::Transparent);
    minimapBorder.setPosition(5, 20); // Set position as per your requirements
}

void MiniMap::render(sf::RenderWindow &window, const Player &player, const std::vector<std::shared_ptr<Enemy>> &enemies)
{
    window.setView(miniMapView);
    renderPlayer(window, player);
    renderEnemies(window, enemies);
}

void MiniMap::renderPlayer(sf::RenderWindow &window, const Player &player)
{
    sf::CircleShape playerIndicator(5);
    playerIndicator.setFillColor(sf::Color::Green);
    playerIndicator.setPosition(player.getPosition()); // Ensure getPosition returns the correct coordinates for the minimap
    window.draw(playerIndicator);
    window.draw(minimapBorder);
}

void MiniMap::renderEnemies(sf::RenderWindow &window, const std::vector<std::shared_ptr<Enemy>> &enemies)
{
    for (const auto &enemy : enemies)
    {
        if (enemy->isVisible())
        {
            sf::CircleShape enemyIndicator(5);
            enemyIndicator.setFillColor(sf::Color::Red);
            enemyIndicator.setPosition(enemy->getSprite().getPosition()); // Adjust as needed
            window.draw(enemyIndicator);
        }
    }
}
