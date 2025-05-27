#ifndef __LEVEL_TEST_E_H
#define __LEVEL_TEST_E_H

#include <utils/Reader.h>

#include <game/level/LevelBase.h>

class LevelTest : public LevelBase
{
  public:
    LevelTest()
        : LevelBase(std::unique_ptr<Player>(new Player(Vector2F(1.5, 1.5) * Config::tile)),
                    std::unique_ptr<Camera>(new Camera(Vector2F(0, 0))),
                    std::unique_ptr<Map>(new Map(Vector2F(0, 0), "map",Reader::loadData("assets/map/map_lvl1.csv"))))
    {
    }

    ~LevelTest() override = default;
};

#endif