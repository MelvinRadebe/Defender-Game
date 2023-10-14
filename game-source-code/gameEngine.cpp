#include "GameEngine.h"
#include "Player.h"
#include "Collisions.h"

const bool Game::isPlaying()
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    inputHandler.handleInput(Play, bullets, *window);
}

void Game::update()
{
    this->pollEvent();
    this->Play.update(this->window);
    
    // Enemy spawning logic
    if (enemySpawnClock.getElapsedTime().asSeconds() >= enemySpawnTime && enemies.size() < 6)
    {
        enemies.push_back(std::make_shared<Enemy>());
        enemySpawnClock.restart(); // Reset the clock
    }

    if (fuelCount != 0)
    {
        for (auto &bullet : bullets)
        {
            bullet->move();
        };
        for (auto &enemy : enemies)
        {
            enemy->move();
        };
        for (auto &bullet : enemy_bullets)
        {
            bullet->move();
        }
        
        if (count == 120)
        {
            count = 0;
            auto index = 0;
            while (true)
            {
                index = rand() % enemies.size();
                if (enemies[index]->isVisible())
                {
                    break;
                }
            }
            auto enemy_position = enemies[index]->getSprite().getPosition();
            auto player_position = Play.getPosition();
            enemy_bullets.push_back(make_shared<Enemy_bullet>(enemy_position.x, enemy_position.y, player_position.x, player_position.y));
        }

        if (count % 60 == 0)
        {
            fuelCount -= 5;
            fuelBar.setSize(sf::Vector2f(fuelCount * 2, 15));
        }
        count++;
    }
    isGameOver();

    // Count visible fuel items
    auto fuelVisibleCount = 0;
    for (auto &fuel : _fuel)
    {
        if (fuel->isVisible())
            fuelVisibleCount++;
    }

    for (int i = fuelVisibleCount; i < 4; i++)
    {
        generateFuel();
    }
}


void Game::render()
{
    this->window->clear();
    this->window->draw(this->backgroundSprite);

    // Set the active view to the main view (the game view)
    this->window->setView(this->window->getDefaultView());
    this->window->draw(this->mainBackgroundSprite);

    for (auto &bullet : bullets)
    {
        if (bullet->isVisible())
        {
            window->draw(bullet->getSprite());
        }
    }

    for (auto &bullet : enemy_bullets)
    {
        if (bullet->isVisible())
        {
            window->draw(bullet->getSprite());
        }
    }

    for (auto &enemy : enemies)
    {
        if (enemy->isVisible())
        {
            window->draw(enemy->getSprite());
        }
    }

    for (auto &fuel : _fuel)
    {
        if (fuel->isVisible())
        {
            window->draw(fuel->getSprite());
        }
    }

    window->draw(fuelBar);
    window->draw(fuelBorder);

    // Switch back to the main view for player rendering
    this->window->setView(this->window->getDefaultView());

    // Render the player
    this->Play.render(this->window);

    // Call the render method on the MiniMap instance
    minimap.render(*this->window, Play, enemies); // Assuming 'minimap' is the instance of MiniMap in your Game class

    this->window->display();
}

void Game::initVariables()
{
    this->endGame = false;
    enemies.push_back(std::make_shared<Enemy>());  // Spawn one enemy at the beginning
    this->enemySpawnClock.restart(); // Start the clock for subsequent spawns
    for (int i = 0; i < 4; i++)
    {
        generateFuel();
    }
}

void Game::initWindow(const GameConfig &config)
{
    auto a = config.getWindowWidth();
    auto b = config.getWindowHeight();
    this->videoMode = VideoMode(a, b);
    this->window = new RenderWindow(this->videoMode, config.getWindowTitle(), Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(config.getFrameRateLimit());
    // Initialize other window-related settings using values from 'config'
}

void Game::initWorld()
{
    if (!this->backgroundTexture.loadFromFile("resources/BG.jpg"))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE"
                  << "\n";
    }

    this->backgroundSprite.setTexture(this->backgroundTexture);


    if (!this->mainBackgroundTexture.loadFromFile("resources/SK.png"))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD MAIN GAME BACKGROUND TEXTURE"
                  << "\n";
    }
    this->mainBackgroundSprite.setTexture(this->mainBackgroundTexture);


    fuelBar.setPosition(sf::Vector2f(310, 2));
    fuelBar.setSize(sf::Vector2f(200, 15));
    fuelBar.setFillColor(sf::Color::White);
    fuelBorder.setSize(sf::Vector2f(204, 19));
    fuelBorder.setFillColor(sf::Color::Transparent);
    fuelBorder.setOutlineColor(sf::Color::Blue);
    fuelBorder.setOutlineThickness(2.0f);
    fuelBorder.setPosition(308, 0);
}

Game::Game()
    : gameConfig(), // Initialize the gameConfig object first
                    // Then initialize Play with the gameConfig
      count(0)
{
    this->initVariables();
    this->initWorld();
}

Game::~Game()
{
    delete this->window;
}

// Check if two sprites are colliding

void Game::generateFuel()
{
    float newX, newY;
    bool collision;

    while (true)
    {
        newX = rand() % 512;
        newY = rand() % 512;
        collision = false;

        for (const auto &fuel : _fuel)
        {
            sf::Vector2f fuelPosition = fuel->getSprite().getPosition();
            float distance = std::sqrt((fuelPosition.x - newX) * (fuelPosition.x - newX) + (fuelPosition.y - newY) * (fuelPosition.y - newY));

            if (distance < 30.0f)
            {
                collision = true;
                break;
            }
        }

        if (!collision)
        {
            auto newFuel = make_shared<Fuel>(vector<int>(newX, newY));
            _fuel.push_back(newFuel);
            break;
        }
    }
}