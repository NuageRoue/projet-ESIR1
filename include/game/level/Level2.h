#ifndef __LEVEL_2_H
#define __LEVEL_2_H

#include <utils/Reader.h>

#include <game/level/LevelBase.h>

class Level2 : public LevelBase
{
  public:
    Level2()
        : LevelBase(std::unique_ptr<Player>(new Player(Vector2F(1.5, 1.5) * Config::tile)),
                    std::unique_ptr<Camera>(new Camera(Vector2F(0, 0))),
                    std::unique_ptr<Map>(new Map(Vector2F(0, 0), "map", Reader::loadData("assets/map/map_2.csv"))))
    {
    }

    std::unique_ptr<LevelBase> getNextLevel() override
    {
      return std::unique_ptr<LevelBase>(nullptr);
    }

    ~Level2() override = default;
};

#endif