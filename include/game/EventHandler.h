#ifndef __EVENT_HANDLER__H
#define __EVENT_HANDLER__H

#include <memory>
#include <vector>

class EventHandler
{

  protected:
    static std::unique_ptr<EventHandler> m_singleton;

    std::vector<char> m_active;
    bool m_quit;

    EventHandler();

  public:
    ~EventHandler() = default;

    // singleton no cp
    EventHandler(const EventHandler &) = delete;
    void operator=(const EventHandler &) = delete;

    // singleton things
    static void initialize();
    static void finalize();
    static EventHandler &getInstance();

    // render
    void update();
    const std::vector<char> &getActive() const;
    bool isQuitting() const;
};

#endif