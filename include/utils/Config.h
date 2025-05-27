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
static constexpr char playerTexture[] = "./assets/tiles/player.png";
static constexpr char playerTexture2[] = "./assets/tiles/player2.png";

static constexpr int mapTexturePlage = 10;

static const std::vector<std::string> mapTextures = {"assets/tiles/BRICK2.png", "assets/tiles/water2.png",
                                                     "assets/tiles/lava2.png", "assets/tiles/stairs.png"};

static const std::vector<std::string> mapGrass = {"assets/tiles/grass1.png", "assets/tiles/grass2.png",
                                                  "assets/tiles/grass3.png", "assets/tiles/grass4.png"};

static const std::vector<std::string> mapWall = {"assets/tiles/wall1.png", "assets/tiles/wall2.png"};

static const std::vector<std::vector<std::string>> specialTexture = {mapGrass, mapWall};

static const int startNormalPlage = (specialTexture.size()) * mapTexturePlage;

static const std::vector<int> mapCollision = {mapTexturePlage, mapTexturePlage + 1, startNormalPlage + 2};

}; // namespace Config

#endif