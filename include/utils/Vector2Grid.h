#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <cmath>
#include <utils/MathUtils.h>

class Vector2
{
  private:
    unsigned int m_values[2];

  public:
    Vector2(unsigned int x = 0.0, unsigned int y = 0.0) : m_values{x, y}
    {
    }

    unsigned int operator[](unsigned int index) const
    {
        return m_values[index];
    }

    Vector2 operator+(const Vector2 &v) const
    {
        return Vector2(m_values[0] + v.m_values[0], m_values[1] + v.m_values[1]);
    }

    Vector2 operator-(const Vector2 &v) const
    {
        return Vector2(m_values[0] - v.m_values[0], m_values[1] - v.m_values[1]);
    }

    Vector2 operator*(const unsigned int &v) const
    {
        return Vector2(m_values[0] * v, m_values[1] * v);
    }

    Vector2 operator/(const unsigned int &v) const
    {
        unsigned int div = 1 / v;
        return Vector2(m_values[0] * div, m_values[1] * div);
    }

    Vector2 operator-() const
    {
        return Vector2(-m_values[0], -m_values[1]);
    }

    unsigned int operator*(const Vector2 &v) const
    {
        return m_values[0] * v.m_values[0] + m_values[1] * v.m_values[1];
    }

    unsigned int norm() const
    {
        return sqrt(m_values[0] * m_values[0] + m_values[1] * m_values[1]);
    }

    Vector2 normalized() const
    {
        return (*this) / norm();
    }

    bool operator==(const Vector2 &v) const
    {
        return m_values[0] == v.m_values[0] && m_values[1] == v.m_values[1];
    }

    bool operator!=(const Vector2 &v) const
    {
        return !((*this) == v);
    }

    Vector2 rotate(const unsigned int &angle) const
    {
        unsigned int c = std::cos(angle);
        unsigned int s = std::sin(angle);
        return Vector2(c * m_values[0] - s * m_values[1], s * m_values[0] + c * m_values[1]);
    }

    unsigned int distance(const Vector2 &v) const
    {
        return ((*this) - v).norm();
    }

    Vector2 direction(const Vector2 &v) const
    {
        return (v - (*this)).normalized();
    }
};

#endif //_VECTOR2_H
