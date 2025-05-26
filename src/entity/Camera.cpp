#include <entity/Camera.h>

#include <utils/Config.h>

#include <game/GameManager.h>

const std::string Camera::nameCamera = "camera";

Camera::Camera(const Vector2 &position) : Entity(position, nameCamera, 0)
{
}

void Camera::update()
{
    auto position =
        GameManager::getLevel().m_hero->getPosition() * Config::unit - Vector2(Config::width, Config::height) / 2;
    
}

void Camera::render(const Vector2 &ref)
{
}