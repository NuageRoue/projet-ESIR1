#include <game/GameManager.h>

#include <entity/Camera.h>

Camera::Camera(const Vector2F &position) : Entity(position, "camera", 0)
{
}

void Camera::render(const Vector2F &ref)
{
}

void Camera::update()
{
    setPosition(GameManager::getLevel().getPlayer().getPosition() - (Vector2F(Config::width, Config::height) / 2));
}