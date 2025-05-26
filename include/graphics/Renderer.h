#ifndef _Renderer_H
#define _Renderer_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>

#include <utils/config.h>

#include <memory>

#include <algorithm>
#include <map>
#include <vector>

#include <iostream>

#include <graphics/texture/Texture.h>
#include <utils/Vector2.h>

class Texture;

class Renderer
{

  protected:
    static std::unique_ptr<Renderer> m_singleton;

    SDL_Window *m_window;     // fenêtre de rendu (SDL)
    SDL_Renderer *m_renderer; // Moteur de rendu interne à SDL

    Renderer();

  public:
    Renderer(const Renderer &) = delete;
    void operator=(const Renderer &) = delete;

    ~Renderer();

    SDL_Renderer *getSdlRenderer() const
    {
        return m_renderer;
    }

    static void initialize();

    static void finalize();

    static Renderer *getInstance();

    void render();

    void drawString(const std::string &text, Vector2 const &position, TTF_Font *font, const SDL_Color &color,
                    double size);

    void drawTexture(SDL_Texture *texture, const SDL_Rect *src, const SDL_Rect *dest);
    void drawTexture(const Texture *texture, const Vector2 &center, const Vector2 &scale, float rotation);
};

#endif
