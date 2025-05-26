#include <cassert>
#include <iostream>

#include <SDL2/SDL.h>

#include <game/EventHandler.h>

std::unique_ptr<EventHandler> EventHandler::m_singleton = nullptr;

EventHandler::EventHandler() : m_active(), m_quit(false)
{
}

void EventHandler::initialize()
{
    std::cout << "Initialize Event handler" << std::endl;
    m_singleton = std::unique_ptr<EventHandler>(new EventHandler());
}

void EventHandler::finalize()
{
    m_singleton = nullptr;
}

EventHandler &EventHandler::getInstance()
{
    assert(m_singleton != nullptr);
    return *m_singleton;
}

void EventHandler::update()
{
    m_active.clear();

    SDL_Event event;
    char current;

    while (SDL_PollEvent(&event))
    {
        if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == 'm'))
        {
            m_quit = true;
        }

        if (event.type == SDL_KEYDOWN)
        {
            current = (char)event.key.keysym.sym;
            std::cout << current << std::endl;
            m_active.push_back(current);
        }
    }
}

const std::vector<char> &EventHandler::getActive() const
{
    return m_active;
}

bool EventHandler::isQuitting() const
{
    return m_quit;
}