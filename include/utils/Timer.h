#ifndef __TIMER__H
#define __TIMER__H

#include <SDL2/SDL.h>

#include <memory>


class Timer
{
  public:
    static constexpr double tps = 60;
    static constexpr double tkPerFrame = 1000 / tps;

  protected:
    static std::unique_ptr<Timer> m_singleton;

    Uint64 m_startTicks;
    Uint64 m_count;

    Timer();

  public:
    ~Timer() = default;

    Timer(const Timer &copy) = delete;
    Timer &operator=(const Timer &copy) = delete;

    static Timer &getInstance();

    Uint64 getTicks() const;
    double getSeconds() const;

    void start();
    void stop();
    void update();
};

#endif