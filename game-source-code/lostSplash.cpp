#include "LostSplash.h"
#include <iostream>

LostScreen::LostScreen(sf::RenderWindow* parentWindow)
    : window(parentWindow)
{
    if (!backgroundTexture.loadFromFile("resources/Outcome.png"))
    {
        std::cout << "Could not load background image" << std::endl;
        return;
    }

    if (!font.loadFromFile("resources/SportypoReguler-OVGwe.ttf"))
    {
        std::cout << "Could not load font" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);

    text.setFont(font);
    text.setString("You Lost!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);

    // Center the text
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(parentWindow->getSize().x / 2.0f, parentWindow->getSize().y / 2.0f);
}

void LostScreen::showLostScreen()
{
    sf::RenderWindow lostWindow(sf::VideoMode(700, 400), "You Lost!");

    // Main loop for the lost screen
    while (lostWindow.isOpen())
    {
        sf::Event event;
        while (lostWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                lostWindow.close();
            }
        }

        lostWindow.clear();
        lostWindow.draw(backgroundSprite);
        lostWindow.draw(text);
        lostWindow.display();
    }
}
