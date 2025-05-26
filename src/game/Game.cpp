#include <entity/Entity.h>
#include <graphics/Renderer.h>

#include <iostream>

#include <game/Game.h>

Game::Game() : m_gameState(GameState::PLAY), m_pressed()
{
    initGame();
    GameManager::initialize();
    GameManager::getInstance().m_pressed = &m_pressed;
}

Game::~Game()
{
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

    // Load Texture
    // Theme::loadTextureMap();
}


void Game::gameLoop()
{

    while (m_gameState != GameState::EXIT)
    {
        Timer::getInstance().start();

        // récupérer les touches appuyées
        // vérifier si on appuie que q -> quitte le jeu
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == 'm'))
            {
                std::cout << "Exit signal detected" << std::endl;
                m_gameState = GameState::EXIT;
                break;
            }
            if (event.type == SDL_KEYDOWN)
            {
                m_pressed.insert((char)event.key.keysym.sym);
            }
        }

        // 2 - We update the simulation
        update();

        // 3 - We render the scene
        render();

        // 4 - We limit the frame rate
        Uint64 frameTime = Timer::getInstance().getTicks();
        if (TICKS_PER_FRAME > frameTime)
        {
            SDL_Delay(TICKS_PER_FRAME - frameTime);
        }

        m_pressed.clear();
    }
}

void Game::update()
{
    GameManager::getInstance().update();
}

void Game::render()
{
    GameManager::getInstance().render();

    Renderer::getInstance()->render();
}

void Game::endGame()
{
    GameManager::finalize();
    std::cout << "Shutting down renderer..." << std::endl;
    Renderer::finalize();
    std::cout << "Shutting down SDL" << std::endl;
    SDL_Quit();
}