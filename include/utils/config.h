#ifndef _CONFIG_H
#define _CONFIG_H

#include <utils/MathUtils.h>

namespace Constants
{
static constexpr MathUtils::Size tile = 128;
static constexpr MathUtils::Size width = tile * 11;
static constexpr MathUtils::Size height = tile * 7;
}; // namespace Constants

#endif //_CONFIG_H