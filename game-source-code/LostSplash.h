#pragma once

#include <SFML/Graphics.hpp>

class LostScreen {
public:
    LostScreen(sf::RenderWindow* parentWindow);

    void showLostScreen();

private:
    sf::RenderWindow* window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text text;
};
