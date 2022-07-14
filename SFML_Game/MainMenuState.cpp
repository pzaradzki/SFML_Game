#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window) 
    : GameState(window)
{
    backgroundTexture.loadFromFile("Images/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    btnStartTexture.loadFromFile("Images/btnStart.png");
    btnStartSprite.setTexture(btnStartTexture);

    titleTexture.loadFromFile("Images/title.png");
    titleSprite.setTexture(titleTexture);

    btnStartSprite.setPosition(
        window->getSize().x / 2 - btnStartSprite.getGlobalBounds().width / 2,
        window->getSize().y / 2 - btnStartSprite.getGlobalBounds().height / 2
    );
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::MouseButtonPressed)
        if (event->mouseButton.button == sf::Mouse::Left)
            if(buttonClicked())
                Game::state = Game::Playing;
}

void MainMenuState::update(float elapsedTime)
{
}

void MainMenuState::draw()
{
    window->draw(backgroundSprite);
    window->draw(btnStartSprite);
    window->draw(titleSprite);
}

bool MainMenuState::buttonClicked()
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);

    bool isClicked = btnStartSprite.getGlobalBounds().contains(worldPos);
    if (isClicked)
    {
        std::cout << "isClicked: " << (isClicked ? "true" : "false") << std::endl;
        return true;
    }
    else
    {
        std::cout << "isClicked: " << (isClicked ? "true" : "false") << std::endl;
        return false;
    }
}