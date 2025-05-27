#ifndef __LEVEL_GROTTE_H
#define __LEVEL_GROTTE_H

#include <utils/Reader.h>

#include <game/level/Level2.h>
#include <game/level/LevelTest.h>

class LevelGrotte : public LevelBase
{
  public:
    LevelGrotte()
        : LevelBase(std::unique_ptr<PlayerWord>(new PlayerWord(Vector2F(4.5, 4.5) * Config::tile)),
                    std::unique_ptr<Camera>(new Camera(Vector2F(0, 0))),
                    std::unique_ptr<Map>(new Map(Vector2F(0, 0), "map", Reader::loadData("assets/map/map_grotte.csv"))),
                    std::unique_ptr<EndMap>(new EndMap(Vector2F(4, 4))))
    {
    }

    std::unique_ptr<LevelBase> getNextLevel() override
    {
        return std::unique_ptr<LevelBase>(new Level2());
    }

    ~LevelGrotte() override = default;
};

#endif