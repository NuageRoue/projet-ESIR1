#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>

#include <graphics/Renderer.h>
class Texture;

class TextureManager
{
  protected:
    static std::unique_ptr<TextureManager> m_singleton;

    std::unordered_map<int, std::shared_ptr<Texture>> m_textures;

    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textureEntities;

    friend class Renderer;

    TextureManager();

  public:
    virtual ~TextureManager();
    TextureManager(const TextureManager &copy) = delete;
    TextureManager &operator=(const TextureManager &copy) = delete;

    static TextureManager *getInstance();

    std::shared_ptr<Texture> loadTexture(const std::string &filename, const std::string &value);

    Texture *get(const std::string &value) const;

    void removeTexture(const std::string &value);

    void removeAllTexture();

    static void initialize();

    static void finalize();
};

#endif
