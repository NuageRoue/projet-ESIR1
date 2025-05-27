#ifndef __LEVEL_TEST_H
#define __LEVEL_TEST_H

#include <game/level/LevelBase.h>

class LevelTest : public LevelBase
{
  public:
    LevelTest()
        : LevelBase(std::unique_ptr<Player>(new Player(Vector2F(1.5, 1.5) * Config::tile)),
                    std::unique_ptr<Camera>(new Camera(Vector2F(0, 0))),
                    std::unique_ptr<Map>(new Map(Vector2F(0, 0), "map")))
    {
    }

    ~LevelTest() override = default;
};

#endif