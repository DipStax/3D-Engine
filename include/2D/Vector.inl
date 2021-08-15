/*
** DipStax 2021
** 3D-Engine
** File description:
** Vector.cpp
*/

#include "Vector.hpp"

namespace d2 {

    template<typename T>
    Vector<T>::Vector(const T &_x, const T &_y)
    {
        x = _x;
        y = _y;
    }

    template<typename T>
    Vector<T>::Vector(const Vector<T> &_vec)
    {
        x = _vec.x;
        y = _vec.y;
    }
}