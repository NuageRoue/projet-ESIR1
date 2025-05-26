#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>
#include <unordered_map>

#include <graphics/texture/Texture.h>
#include <graphics/Renderer.h>

class TextureManager
{
  protected:
    static std::unique_ptr<TextureManager> m_singleton;

    std::unordered_map<std::string, std::unique_ptr<Texture>> m_loaded;

    // init singleton
    TextureManager();

  public:
    ~TextureManager();

    // singleton cp
    TextureManager(const TextureManager &copy) = delete;
    TextureManager &operator=(const TextureManager &copy) = delete;

    // singleton things
    static void initialize();
    static void finalize();
    static TextureManager &getInstance();

    // others
    Texture *loadTexture(const std::string &filename, const std::string &value);
    Texture *getTexture(const std::string &value) const;
    
    void removeTexture(const std::string &value);
    void removeAllTexture();
};

#endif
