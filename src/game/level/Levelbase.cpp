#include <algorithm>

#include <game/level/LevelBase.h>

LevelBase::LevelBase(std::unique_ptr<PlayerWord> player, std::unique_ptr<Camera> camera, std::unique_ptr<Map> map,std::unique_ptr<EndMap> endmap)
    : m_entities(), m_player(std::move(player)), m_camera(std::move(camera)), m_map(std::move(map)), m_endmap(std::move(endmap))
{
}

#include <iostream>

void LevelBase::render()
{
    const Vector2F ref = -m_camera->getPosition();

    m_map->render(ref);

    std::sort(m_entities.begin(), m_entities.end(),
              [](const std::unique_ptr<Entity> &a, const std::unique_ptr<Entity> &b) {
                  return a->getLayer() < b->getLayer();
              });

    std::for_each(m_entities.begin(), m_entities.end(),
                  [&ref](const std::unique_ptr<Entity> &entity) { entity->render(ref); });

    m_player->render(ref);
    m_camera->render(ref);
}

void LevelBase::update()
{
    std::for_each(m_entities.begin(), m_entities.end(),
                  [](const std::unique_ptr<Entity> &entity) { entity->update(); });

    m_player->update();
    m_camera->update();
    m_map->update();
    m_endmap->update();
}



PlayerWord &LevelBase::getPlayer()
{
    return *m_player.get();
}

Camera &LevelBase::getCamera()
{
    return *m_camera.get();
}

Map &LevelBase::getMap()
{
    return *m_map.get();
}

EndMap &LevelBase::getEndMap(){
    return *m_endmap.get();
}