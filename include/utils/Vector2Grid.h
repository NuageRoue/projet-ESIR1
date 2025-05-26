#ifndef _Vector2Grid_H
#define _Vector2Grid_H

#include <cmath>
#include <utils/MathUtils.h>

#include <utils/Vector2.h>

class Vector2Grid
{
  private:
    friend class Vector2;

    unsigned int m_values[2];

  public:
    Vector2Grid(unsigned int x = 0.0, unsigned int y = 0.0) : m_values{x, y}
    {
    }

    unsigned int operator[](unsigned int index) const
    {
        return m_values[index];
    }

    Vector2Grid operator+(const Vector2Grid &v) const
    {
        return Vector2Grid(m_values[0] + v.m_values[0], m_values[1] + v.m_values[1]);
    }

    Vector2Grid operator-(const Vector2Grid &v) const
    {
        return Vector2Grid(m_values[0] - v.m_values[0], m_values[1] - v.m_values[1]);
    }

    Vector2Grid operator*(const unsigned int &v) const
    {
        return Vector2Grid(m_values[0] * v, m_values[1] * v);
    }

    Vector2Grid operator/(const unsigned int &v) const
    {
        unsigned int div = 1 / v;
        return Vector2Grid(m_values[0] * div, m_values[1] * div);
    }

    Vector2Grid operator-() const
    {
        return Vector2Grid(-m_values[0], -m_values[1]);
    }

    unsigned int operator*(const Vector2Grid &v) const
    {
        return m_values[0] * v.m_values[0] + m_values[1] * v.m_values[1];
    }

    unsigned int norm() const
    {
        return sqrt(m_values[0] * m_values[0] + m_values[1] * m_values[1]);
    }

    Vector2Grid normalized() const
    {
        return (*this) / norm();
    }

    bool operator==(const Vector2Grid &v) const
    {
        return m_values[0] == v.m_values[0] && m_values[1] == v.m_values[1];
    }

    bool operator!=(const Vector2Grid &v) const
    {
        return !((*this) == v);
    }

    Vector2Grid rotate(const unsigned int &angle) const
    {
        unsigned int c = std::cos(angle);
        unsigned int s = std::sin(angle);
        return Vector2Grid(c * m_values[0] - s * m_values[1], s * m_values[0] + c * m_values[1]);
    }

    unsigned int distance(const Vector2Grid &v) const
    {
        return ((*this) - v).norm();
    }

    Vector2Grid direction(const Vector2Grid &v) const
    {
        return (v - (*this)).normalized();
    }
};

#endif //_Vector2Grid_H
