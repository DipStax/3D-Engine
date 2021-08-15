/*
** DipStax 2021
** 3D-Engine
** File description:
** Vector.hpp
*/

#pragma once

#include "Point.hpp"

namespace d3 {

    template<typename T>
    class Vector {
        static_assert(std::is_arithmetic<T>::value);
        public:
            Vector() = default;
            Vector(const T &_x, const T &_y, const T &_z);
            Vector(const Vector<T> &_vec);
            Vector(const Point<T> &_pt);

            virtual ~Vector() = default;

            Vector<T> &operator=(const Vector<T> &_pt);

            [[nodiscard]] float lenght() const;
            [[nodiscard]] Vector<T> normalise() const;

            [[nodiscard]] Vector<T> crossProduct(const Vector<T> &_vec) const;
            [[nodiscard]] T dotProduct(const Vector<T> &_vec) const;

            T x = 0;
            T y = 0;
            T z = 0;
            T w = 0;
        private:
    };

    using Vectorf = Vector<float>;
    using Vectori = Vector<int>;
    using Vectord = Vector<double>;
    using Vectoru = Vector<unsigned int>;
}

template<typename T>
d3::Vector<T> operator+(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd);
template<typename T>
d3::Vector<T> operator+(const d3::Vector<T> &_vec, const T &_n);
template<typename T>
d3::Vector<T> operator-(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd);
template<typename T>
d3::Vector<T> operator-(const d3::Vector<T> &_vec, const T &_n);
template<typename T>
d3::Vector<T> operator*(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd);
template<typename T>
d3::Vector<T> operator*(const d3::Vector<T> &_vec, const T &_n);
template<typename T>
d3::Vector<T> operator/(const d3::Vector<T> &_fst, const d3::Vector<T> &_snd);
template<typename T>
d3::Vector<T> operator/(const d3::Vector<T> &_vec, const T &_n);

#include "Vector.inl"