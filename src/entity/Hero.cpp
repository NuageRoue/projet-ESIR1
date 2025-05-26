#include <entity/Hero.h>

Hero::Hero(const Vector2 &position, const Vector2 &size, const std::string &filename, const std::string &nameEntity)
    : DrawEntity(position, size, filename, nameEntity)
{
}

Hero::~Hero()
{
}

void Hero::update()
{
    // récupérer les touches appuyées
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RETURN:
                std::cout << "Enter" << ::std::endl;
                break;
            case SDLK_RIGHT:
                std::cout << "Right down" << ::std::endl;
                break;
            case SDLK_LEFT:
                std::cout << "Left down" << ::std::endl;
                break;
            case SDLK_UP:
                std::cout << "Up down" << ::std::endl;
                break;
            case SDLK_DOWN:
                std::cout << "Down down" << ::std::endl;
                break;
            case SDLK_SPACE:
                std::cout << "space down" << ::std::endl;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                std::cout << "Left up" << ::std::endl;
                break;
            case SDLK_RIGHT:
                std::cout << "Right up" << ::std::endl;
                break;
            case SDLK_UP:
                std::cout << "up up" << ::std::endl;
                break;
            case SDLK_DOWN:
                std::cout << "down up" << ::std::endl;
                break;
            case SDLK_SPACE:
                std::cout << "space up" << ::std::endl;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Hero::render()
{
    DrawEntity::render();
}