/*
** DipStax 2021
** 3D-Engine
** File description:
** Point.hpp
*/

#pragma once

#include <type_traits>

namespace d3 {

    template<typename T>
    class Point {
        static_assert(std::is_arithmetic<T>::value);
        public:
            Point() = default;
            Point(const T &_x, const T &_y, const T &_z);
            Point(const Point<T> &_pt);

            virtual ~Point() = default;

            Point<T> &operator=(const Point<T> &_pt);

            virtual void setPosition(const Point<T> &_pt);
            virtual void setPosition(const T &_x, const T &_y, const T &_z);

            virtual void move(const Point<T> &pt);
            virtual void move(const T &_x, const T &_y, const T &_z);

            T x = 0;
            T y = 0;
            T z = 0;
            T w = 0;
    };

    using Pointf = Point<float>;
    using Pointi = Point<int>;
    using Pointd = Point<double>;
    using Pointu = Point<unsigned int>;
}


template<typename T>
d3::Point<T> operator+(const d3::Point<T> &_fst, const d3::Point<T> &_snd);
template<typename T>
d3::Point<T> operator+(const d3::Point<T> &_pt, const T &_n);
template<typename T>
d3::Point<T> operator-(const d3::Point<T> &_fst, const d3::Point<T> &_snd);
template<typename T>
d3::Point<T> operator-(const d3::Point<T> &_pt, const T &_n);
template<typename T>
d3::Point<T> operator*(const d3::Point<T> &_fst, const d3::Point<T> &_snd);
template<typename T>
d3::Point<T> operator*(const d3::Point<T> &_pt, const T &_n);
template<typename T>
d3::Point<T> operator/(const d3::Point<T> &_fst, const d3::Point<T> &_snd);
template<typename T>
d3::Point<T> operator/(const d3::Point<T> &_pt, const T &_n);

#include "Point.inl"