#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <utils/MathUtils.h>

#include <graphics/Renderer.h>

class Texture
{

  private:
    SDL_Texture *m_texture;
    std::string m_filename;
    int m_width;
    int m_height;

  protected:
    SDL_Texture *loadTexture(const std::string &filename);

    void removeTexture();

  public:
    Texture(const std::string &filename);
    Texture(const Texture &copy);
    Texture &operator=(const Texture &copy);
    bool operator==(const Texture &other);

    virtual ~Texture();

    SDL_Texture *get() const;
    const std::string &getFilename() const;
    MathUtils::Size getWidth() const;
    MathUtils::Size getHeight() const;
};

#endif //_TEXTURE_H
