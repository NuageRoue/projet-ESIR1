#ifndef __END_MAP__H
#define __END_MAP__H

#include <entity/Entity.h>

class EndMap : public Entity
{

  public:
    Vector2F m_grid;
    bool m_fin;

    EndMap(Vector2F grid);
    ~EndMap() override = default;

    void update() override;
    void render(const Vector2F &ref) override;
};

#endif