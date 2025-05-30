#ifndef _Renderer_H
#define _Renderer_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>

#include <memory>

#include <graphics/texture/Texture.h>
#include <graphics/texture/TextureManager.h>
#include <utils/Config.h>
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
    ~Renderer();

    // singleton no cp
    Renderer(const Renderer &) = delete;
    void operator=(const Renderer &) = delete;

    // singleton things
    static void initialize();
    static void finalize();
    static Renderer &getInstance();

    // renderer
    SDL_Renderer *getSdlRenderer() const;

    // render
    void render();

    // draw
    void drawString(const std::string &text, Vector2F const &position, TTF_Font *font, const SDL_Color &color);
    void drawTexture(SDL_Texture *texture, const SDL_Rect *src, const SDL_Rect *dest);
    void drawTexture(const Texture *texture, const Vector2F &center, const Vector2F &scale, float rotation);
};

#endif
