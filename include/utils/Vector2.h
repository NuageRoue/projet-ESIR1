#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <cmath>
#include <iostream>

template <class T> class Vector2
{

  private:
    T m_values[2];

  public:
    Vector2(T x = 0.0, T y = 0.0) : m_values{x, y}
    {
    }


    T operator[](unsigned int index) const
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

    Vector2 operator*(const T &v) const
    {
        return Vector2(m_values[0] * v, m_values[1] * v);
    }

    Vector2 operator/(const T &v) const
    {
        T div = T(1) / v;
        return Vector2(m_values[0] * div, m_values[1] * div);
    }

    Vector2 operator-() const
    {
        return Vector2(-m_values[0], -m_values[1]);
    }

    T operator*(const Vector2 &v) const
    {
        return m_values[0] * v.m_values[0] + m_values[1] * v.m_values[1];
    }

    T norm() const
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

    Vector2 rotate(const T &angle) const
    {
        T c = std::cos(angle);
        T s = std::sin(angle);
        return Vector2(c * m_values[0] - s * m_values[1], s * m_values[0] + c * m_values[1]);
    }

    T distance(const Vector2 &v) const
    {
        return ((*this) - v).norm();
    }

    Vector2 direction(const Vector2 &v) const
    {
        return (v - (*this)).normalized();
    }

    Vector2<int> floor() const
    {
        return Vector2<int>(m_values[0], m_values[1]);
    }
};

using Vector2F = Vector2<float>;
using Vector2I = Vector2<int>;
#endif //_VECTOR2_H
