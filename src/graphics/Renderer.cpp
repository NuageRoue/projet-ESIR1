#include <iostream>

#include <graphics/Renderer.h>

std::unique_ptr<Renderer> Renderer::m_singleton = nullptr;

Renderer::Renderer()
{
    if (SDL_CreateWindowAndRenderer(Config::width, Config::height, SDL_WINDOW_SHOWN, &m_window, &m_renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        exit(3);
    }
    SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
    SDL_SetWindowTitle(m_window, "Jeu ESIR");

    TextureManager::initialize(); // init texture manager
}

Renderer::~Renderer()
{
    TextureManager::finalize(); // end texture manager

    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

void Renderer::initialize()
{
    std::cout << "Initialize Renderer" << std::endl;
    m_singleton = std::unique_ptr<Renderer>(new Renderer());
}

void Renderer::finalize()
{
    m_singleton = nullptr;
}

Renderer &Renderer::getInstance()
{
    return *m_singleton;
}

void Renderer::render()
{
    // After drawing
    SDL_RenderPresent(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

SDL_Renderer *Renderer::getSdlRenderer() const
{
    return m_renderer;
}

void Renderer::drawString(const std::string &text, Vector2F const &position, TTF_Font *font, const SDL_Color &color)
{
    SDL_Surface *surfaceText = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surfaceText == nullptr)
    {
        throw std::runtime_error(TTF_GetError());
    }
    SDL_Texture *textureText = SDL_CreateTextureFromSurface(m_renderer, surfaceText);
    if (textureText == nullptr)
    {
        SDL_FreeSurface(surfaceText);
        throw std::runtime_error(SDL_GetError());
    }
    SDL_Rect rect = {(int)position[0], (int)position[1], surfaceText->w, surfaceText->h};
    // rect.x = position[0]-surfaceText->w/2;
    // rect.y = position[1]-surfaceText->h/2;

    SDL_RenderCopy(m_renderer, textureText, nullptr, &rect);
    SDL_DestroyTexture(textureText);
    SDL_FreeSurface(surfaceText);
}

void Renderer::drawTexture(SDL_Texture *texture, const SDL_Rect *src, const SDL_Rect *dest)
{
    SDL_RenderCopy(m_renderer, texture, src, dest);
}

void Renderer::drawTexture(const Texture *texture, const Vector2F &center, const Vector2F &scale, float rotation)
{
    SDL_Rect rect; // localization and size of the texture
    rect.x = center[0] - scale[0] / 2;
    rect.y = center[1] - scale[1] / 2;
    rect.w = scale[0];
    rect.h = scale[1];
    SDL_Texture *text = texture->getSDL();
    SDL_RenderCopyEx(m_renderer, text, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);
}