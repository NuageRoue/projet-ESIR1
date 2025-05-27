#ifndef _CONFIG_H
#define _CONFIG_H

#include <string>
#include <vector>

namespace Config
{

using Size = int;
static constexpr Size tile = 128;

static constexpr Size width = tile * 11.5;
static constexpr Size height = tile * 6.5;

static constexpr unsigned int playerLayer = 10;
static constexpr char playerTag[] = "player";
static constexpr char playerTexture[] = "./assets/tiles/liquidWater.png";

static const std::vector<std::string> mapTextures = {"assets/tiles/BRICK2.png", "assets/tiles/WATER.png",
                                                     "assets/tiles/LAVA.png"};

static const std::vector<std::string> mapGrass = {"assets/tiles/grass1.png", "assets/tiles/grass2.png",
                                                  "assets/tiles/grass3.png", "assets/tiles/grass4.png"};

static const std::vector<int> mapCollision = {10};

}; // namespace Config

#endif