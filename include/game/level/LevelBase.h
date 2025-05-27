#ifndef __LEVEL_BASE__H
#define __LEVEL_BASE__H

#include <memory>
#include <vector>

#include <entity/Camera.h>
#include <entity/Entity.h>
#include <entity/Map.h>
#include <entity/PlayerWord.h>
#include <entity/EndMap.h>

class LevelBase
{

  private:
    friend class Camera;

    std::vector<std::unique_ptr<Entity>> m_entities; // set avec toutes les entites du jeu
  protected:
    std::unique_ptr<PlayerWord> m_player;
    std::unique_ptr<Camera> m_camera;
    std::unique_ptr<Map> m_map;
    std::unique_ptr<EndMap> m_endmap;

    LevelBase(std::unique_ptr<PlayerWord> player, std::unique_ptr<Camera> camera, std::unique_ptr<Map> map,std::unique_ptr<EndMap> endmap);

  public:
    virtual ~LevelBase() = default;

    void render();
    void update();

    virtual std::unique_ptr<LevelBase> getNextLevel() = 0;

    PlayerWord &getPlayer();
    Camera &getCamera();
    Map &getMap();
    EndMap &getEndMap();
};

#endif