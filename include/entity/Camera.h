#ifndef _CAMERA_H
#define _CAMERA_H

#include <graphics/texture/Texture.h>
#include <graphics/texture/TextureManager.h>

#include <entity/Entity.h>

#include <memory>

class Camera : public Entity
{

  public:
    static const std::string nameCamera;

  public:
    // Constructeur et destructeur
    Camera(const Vector2 &position);
    ~Camera() override = default;

    // update et render
    void render(const Vector2 &ref) override;
    void update() override;
};

#endif