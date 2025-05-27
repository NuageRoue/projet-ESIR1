// #include <entity/Entity.h>
#include <iostream>

#include <game/Game.h>

#include <game/EventHandler.h>
#include <game/GameManager.h>
#include <graphics/Renderer.h>

Game::Game() : m_gameState(GameState::PLAY)
{
    initGame();
    // GameManager::initialize();
    // GameManager::getInstance().m_pressed = &m_pressed;
}

void Game::run()
{
    gameLoop();
    endGame();
}

void Game::initGame()
{

    // 1 - Initialization of SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(3);
    }

    Renderer::initialize();
    EventHandler::initialize();
    GameManager::initialize();
}

//boucle du jeu
void Game::gameLoop()
{
    while (m_gameState != GameState::EXIT)
    {
        Timer::getInstance().start();

        //recuperer touches pressees
        EventHandler &event = EventHandler::getInstance();
        event.update();
        //si on appuye pour quitter
        if (event.isQuitting())
        {
            std::cout << "Exit signal detected" << std::endl;
            m_gameState = GameState::EXIT;
            break;
        }

        GameManager &manager = GameManager::getInstance();
        manager.update();

        //si on a atteint fin du jeu
        if (manager.finalEnd())
        {
            m_gameState = GameState::END;
            break;
        }

        manager.render();

        Renderer::getInstance().render();

        // We limit the frame rate
        Uint64 frameTime = Timer::getInstance().getTicks();
        if (Timer::tkPerFrame > frameTime)
        {
            SDL_Delay(Timer::tkPerFrame - frameTime);
        }
    }
}

void Game::endGame()
{
    {
        EventHandler &event = EventHandler::getInstance();
        //charger ecran fin
        Texture *texture = TextureManager::getInstance().loadTexture("assets/fini.png", "textureFin");
        Renderer &render = Renderer::getInstance();
        //affichage ecran fin
        while (event.isQuitting() == false)
        {
            event.update();
            render.drawTexture(texture, Vector2F(Config::width, Config::height) / 2,
                               Vector2F(Config::width, Config::height), 0.0f);
            render.render();
        }
    }

    std::cout << "Shutting down game manager" << std::endl;
    GameManager::finalize();

    std::cout << "Shutting down event handler" << std::endl;
    EventHandler::finalize();

    std::cout << "Shutting down renderer" << std::endl;
    Renderer::finalize();

    std::cout << "Shutting down SDL" << std::endl;
    SDL_Quit();
}