#ifndef __LEVEL1_H
#define __LEVEL1_H

#include <game/level/LevelBase.h>

class Level1 : public LevelBase
{

  public:
    Level1()
        : LevelBase(std::unique_ptr<Hero>(
                        new Hero(Vector2(0.5, 0.5), 2, std::vector<std::string>{"./assets/tiles/liquidWater.png"})),
                    std::unique_ptr<Map>(new Map(Vector2(0, 0), "map")),
                    std::unique_ptr<Camera>(new Camera(Vector2(1, 1))))
    {
    }

    ~Level1() override = default;
};

#endif