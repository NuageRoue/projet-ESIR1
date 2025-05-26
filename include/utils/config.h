#ifndef _CONFIG_H
#define _CONFIG_H

#include <utils/MathUtils.h>

namespace Constants
{
static constexpr MathUtils::Size tile = 64;
static constexpr MathUtils::Size width = tile * 16;
static constexpr MathUtils::Size height = tile * 12;
}; // namespace Constants

#endif //_CONFIG_H