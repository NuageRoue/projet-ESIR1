#ifndef _CONFIG_H
#define _CONFIG_H

#include <utils/MathUtils.h>

namespace Config
{
static constexpr MathUtils::Size unit = 128;
static constexpr MathUtils::Size unitX = 11;
static constexpr MathUtils::Size unitY = 7;

static constexpr MathUtils::Size width = unit * unitX;
static constexpr MathUtils::Size height = unit * unitY;
}; // namespace Config

#endif //_CONFIG_H