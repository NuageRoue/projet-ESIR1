#include <game/level/LevelBase.h>

LevelBase::LevelBase(std::unique_ptr<Hero> hero, std::unique_ptr<Map> map, std::unique_ptr<Camera> camera)
    : m_hero(std::move(hero)), m_map(std::move(map)), m_camera(std::move(camera))
{
}

void LevelBase::render()
{
    const Vector2 ref = -m_camera->getPosition();

    std::sort(m_entites.begin(), m_entites.end(),
              [](const std::unique_ptr<Entity> &a, const std::unique_ptr<Entity> &b) {
                  return a->getLayer() < b->getLayer();
              });

    m_map->render(ref);

    std::for_each(m_entites.begin(), m_entites.end(),
                  [&ref](const std::unique_ptr<Entity> &entity) { entity->render(ref); });
    m_hero->render(ref);
}

void LevelBase::update()
{
    m_map->update();
    m_hero->update();
    m_camera->update();


    std::for_each(m_entites.begin(), m_entites.end(), [](const std::unique_ptr<Entity> &entity) { entity->update(); });
}