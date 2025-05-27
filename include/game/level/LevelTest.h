#ifndef __LEVEL_TEST_H
#define __LEVEL_TEST_H

#include <utils/Reader.h>

#include <game/level/Level2.h>
#include <game/level/LevelBase.h>

class LevelTest : public LevelBase
{
  public:
    LevelTest()
        : LevelBase(std::unique_ptr<PlayerWord>(new PlayerWord(Vector2F(1.5, 1.5) * Config::tile)),
                    std::unique_ptr<Camera>(new Camera(Vector2F(0, 0))),
                    std::unique_ptr<Map>(new Map(Vector2F(0, 0), "map", Reader::getData())),std::unique_ptr<EndMap>(new EndMap(Vector2F(15,5))))
    {
    }

    std::unique_ptr<LevelBase> getNextLevel() override
    {
        return std::unique_ptr<LevelBase>(new Level2());
    }

    ~LevelTest() override = default;
};

#endif