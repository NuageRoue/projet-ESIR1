#ifndef __LEVEL_BASE_H
#define __LEVEL_BASE_H

#include <entity/Camera.h>
#include <entity/Hero.h>
#include <entity/Map.h>

class LevelBase
{

  private:
    friend class Camera;

    std::unique_ptr<Hero> m_hero;
    std::unique_ptr<Map> m_map;
    std::unique_ptr<Camera> m_camera;

    std::vector<std::unique_ptr<Entity>> m_entites; // set avec toutes les entites du jeu
  protected:
    LevelBase(std::unique_ptr<Hero> hero, std::unique_ptr<Map> map, std::unique_ptr<Camera> camera);

  public:
    virtual ~LevelBase() = default;

    void render();
    void update();
};

#endif