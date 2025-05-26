#ifndef __CAMERA__H
#define __CAMERA__H

#include <entity/Entity.h>

class Camera : public Entity
{
  public:
    Camera(const Vector2F &position);
    ~Camera() override = default;

    // update et render
    void render(const Vector2F &ref) override;
    void update() override;
};

#endif