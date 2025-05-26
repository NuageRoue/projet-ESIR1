#include <entity/Camera.h>

#include <utils/config.h>

#include <game/GameManager.h>

const std::string Camera::nameCamera = "camera";

Camera::Camera(const Vector2 &position) : Entity(position, nameCamera, 0)
{
}

void Camera::update()
{
    Vector2 player = GameManager::getLevel().m_hero->getPosition() * Constants::tile;
    Vector2 delta = Vector2(Constants::width / 2, Constants::height / 2);
    setPosition((player - delta) / Constants::tile);

    std::cout << (player - delta)[0] << ", " << (player - delta)[1] << std::endl;
}

void Camera::render(const Vector2 &ref)
{
}