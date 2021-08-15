/*
** DipStax 2021
** 3D-Engine
** File description:
** Point.inl
*/

#include "3D/Point.hpp"

namespace d3 {
    template<typename T>
    Point<T>::Point(const T &_x, const T &_y, const T &_z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    template<typename T>
    Point<T>::Point(const Point<T> &_pt)
    {
        setPosition(_pt);
    }

    template<typename T>
    Point<T> &Point<T>::operator=(const Point<T> &_pt)
    {
        x = _pt.x;
        y = _pt.y;
        z = _pt.z;
        w = _pt.w;
        return *this;
    }

    template<typename T>
    void Point<T>::setPosition(const Point<T> &_pt)
    {
        x = _pt.x;
        y = _pt.y;
        z = _pt.z;
        w = _pt.w;
    }

    template<typename T>
    void Point<T>::setPosition(const T &_x, const T &_y, const T &_z)
    {
        x = _x;
        y = _y;
        z = _z;
        w = 0;
    }

    template<typename T>
    void Point<T>::move(const Point<T> &_pt)
    {
        x += _pt.x;
        y += _pt.y;
        z += _pt.z;
    }

    template<typename T>
    void Point<T>::move(const T &_x, const T &_y, const T &_z)
    {
        x += _x;
        y += _y;
        z += _z;
    }
}

template<typename T>
d3::Point<T> operator+(const d3::Point<T> &_fst, const d3::Point<T> &_snd)
{
    d3::Point<T> pt(_fst);

    pt.move(_snd);
    return pt;
}

template<typename T>
d3::Point<T> operator+(const d3::Point<T> &_pt, const T &_n)
{
    d3::Point<T> pt(_pt);

    pt.move(_n, _n, _n);
    return pt;
}

template<typename T>
d3::Point<T> operator-(const d3::Point<T> &_fst, const d3::Point<T> &_snd)
{
    d3::Point<T> pt(_fst);

    pt.move(-_snd.x, -_snd.y, -_snd.z);
    return pt;
}

template<typename T>
d3::Point<T> operator-(const d3::Point<T> &_pt, const T &_n)
{
    d3::Point<T> pt(_pt);

    pt.move(-_n, -_n, -_n);
    return pt;
}

template<typename T>
d3::Point<T> operator*(const d3::Point<T> &_fst, const d3::Point<T> &_snd)
{
    d3::Point<T> pt(_fst);

    pt.x *= _snd.x;
    pt.y *= _snd.y;
    pt.z *= _snd.z;
    return pt;
}

template<typename T>
d3::Point<T> operator*(const d3::Point<T> &_pt, const T &_n)
{
    d3::Point<T> pt(_pt);

    pt.x *= _n;
    pt.y *= _n;
    pt.z *= _n;
    return pt;
}

template<typename T>
d3::Point<T> operator/(const d3::Point<T> &_fst, const d3::Point<T> &_snd)
{
    d3::Point<T> pt(_fst);

    pt.x /= _snd.x;
    pt.y /= _snd.y;
    pt.z /= _snd.z;
    return pt;
}

template<typename T>
d3::Point<T> operator/(const d3::Point<T> &_pt, const T &_n)
{
    d3::Point<T> pt(_pt);

    pt.x /= _n;
    pt.y /= _n;
    pt.z /= _n;
    return pt;
}