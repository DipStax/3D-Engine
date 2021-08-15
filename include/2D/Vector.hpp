/*
** DipStax 2021
** 3D-Engine
** File description:
** Vector.hpp
*/

#pragma once

#include <type_traits>

namespace d2 {

    template<typename T>
    class Vector {
        static_assert(std::is_arithmetic<T>::value);
        public:
            Vector() = default;
            Vector(const T &_x, const T &_y);
            Vector(const Vector<T> &_vec);

            virtual ~Vector() = default;

            T x = 0;
            T y = 0;
        private:
    };

    using Vectorf = Vector<float>;
    using Vectori = Vector<int>;
    using Vectord = Vector<double>;
    using Vectoru = Vector<unsigned int>;
}

#include "Vector.inl"