#pragma once

#include <vector>
#include "Player.h"
#include "Enemies.h"
#include <memory>

class MiniMap
{
public:
    MiniMap();
    void render(sf::RenderWindow &window, const Player &player, const std::vector<std::shared_ptr<Enemy>> &enemies);
    void setViewport(const sf::FloatRect &rect);

private:
    sf::View miniMapView;
    sf::RectangleShape minimapBorder;
    void renderPlayer(sf::RenderWindow &window, const Player &player);
    void renderEnemies(sf::RenderWindow &window, const std::vector<std::shared_ptr<Enemy>> &enemies);
};