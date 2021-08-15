/*
** DipStax 2021
** 3D-Engine
** File description:
** Vector.hpp
*/

#include "Vector.hpp"

#include <cmath>

namespace d3 {

    template<typename T>
    Vector<T>::Vector(const T &_x, const T &_y, const T &_z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    template<typename T>
    Vector<T>::Vector(const Vector<T> &_vec)
    {
        x = _vec.x;
        y = _vec.y;
        z = _vec.z;
        w = _vec.w;
    }

    template<typename T>
    Vector<T>::Vector(const Point<T> &_pt)
    {
        x = _pt.x;
        y = _pt.y;
        z = _pt.z;
        w = _pt.w;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(const Vector<T> &_pt)
    {
        x = _pt.x;
        y = _pt.y;
        z = _pt.z;
        w = _pt.w;
        return *this;
    }

    template<typename T>
    float Vector<T>::lenght() const
    {
        return std::sqrt(dotProduct(*this));
    }

    template<typename T>
    Vector<T> Vector<T>::normalise() const
    {
        return (*this) / lenght();
    }

    template<typename T>
    Vector<T> Vector<T>::crossProduct(const Vector<T> &_vec) const
    {
        Vector<T> vec;

        vec.x = y * _vec.z - z * _vec.y;
        vec.y = z * _vec.x - x * _vec.z;
        vec.z = x * _vec.y - y * _vec.x;
        return vec;
    }

    template<typename T>
    T Vector<T>::dotProduct(const Vector<T> &_vec) const
    {
        return x * _vec.x + y * _vec.y + z * _vec.z;
    }
}

template<typename T>
d3::Vector<T> operator+(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd)
{
    d3::Vector<T> vec;

    vec.x = _fst.x + _snd.x;
    vec.y = _fst.y + _snd.y;
    vec.z = _fst.z + _snd.z;
    return vec;
}

template<typename T>
d3::Vector<T> operator+(const d3::Vector<T> &_vec, const T &_n)
{
    d3::Vector<T> vec;

    vec.x = _vec.x + _n;
    vec.y = _vec.y + _n;
    vec.z = _vec.z + _n;
    return vec;
}

template<typename T>
d3::Vector<T> operator-(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd)
{
    d3::Vector<T> vec;

    vec.x = _fst.x - _snd.x;
    vec.y = _fst.y - _snd.y;
    vec.z = _fst.z - _snd.z;
    return vec;
}

template<typename T>
d3::Vector<T> operator-(const d3::Vector<T> &_vec, const T &_n)
{
    d3::Vector<T> vec;

    vec.x = _vec.x - _n;
    vec.y = _vec.y - _n;
    vec.z = _vec.z - _n;
    return vec;
}

template<typename T>
d3::Vector<T> operator*(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd)
{
    d3::Vector<T> vec;

    vec.x = _fst.x * _snd.x;
    vec.y = _fst.y * _snd.y;
    vec.z = _fst.z * _snd.z;
    return vec;
}
template<typename T>
d3::Vector<T> operator*(const d3::Vector<T> &_vec, const T &_n)
{
    d3::Vector<T> vec;

    vec.x = _vec.x * _n;
    vec.y = _vec.y * _n;
    vec.z = _vec.z * _n;
    return vec;
}

template<typename T>
d3::Vector<T> operator/(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd)
{
    d3::Vector<T> vec;

    vec.x = _fst.x / _snd.x;
    vec.y = _fst.y / _snd.y;
    vec.z = _fst.z / _snd.z;
    return vec;
}

template<typename T>
d3::Vector<T> operator/(const d3::Vector<T> &_vec, const T &_n)
{
    d3::Vector<T> vec;

    vec.x = _vec.x / _n;
    vec.y = _vec.y / _n;
    vec.z = _vec.z / _n;
    return vec;
}