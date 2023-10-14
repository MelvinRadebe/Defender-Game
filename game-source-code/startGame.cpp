#include "StartGame.h"

StartGame::StartGame()
{
    // Use the config object to get the game parameters
    window->create(sf::VideoMode(config.getWindowWidth(), config.getWindowHeight()), config.getWindowTitle(), sf::Style::Close | sf::Style::Titlebar);
    // start screen
    manager->replaceState(std::unique_ptr<GameState>(new SplashScreen(manager, window))); // start screen
    run();
}

void StartGame::run()
{
    auto current_time = clock.getElapsedTime().asSeconds();
    auto accumulator = 0.0f;
    while (window->isOpen())
    {
        manager->processState();
        auto new_time = clock.getElapsedTime().asSeconds();
        auto current_frame_time = new_time - current_time;

        // prevent excess accumulation
        if (current_frame_time > 0.25f)
        {
            current_frame_time = 0.25f;
        }

        current_time = new_time;
        accumulator += current_frame_time;

        while (accumulator >= (1.0f / config.getFrameRateLimit())) // Use config object to get frame rate limit
        {
            manager->getCurrentState()->handleInput();
            manager->getCurrentState()->update(1.0f / config.getFrameRateLimit()); // Use config object to get frame rate limit
            accumulator -= (1.0f / config.getFrameRateLimit());                    // Use config object to get frame rate limit
        }

        manager->getCurrentState()->draw();
    }
}
