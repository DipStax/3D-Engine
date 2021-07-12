/*
** DipStax 2021
** 3D-Engine
** File description:
** Matrix.hpp
*/

#pragma once

#include <vector>

#include "3D/Vector.hpp"

namespace Maths {

    template<typename T>
    class Matrix {
        static_assert(std::is_arithmetic<T>::value);
        public:
            Matrix(const std::size_t _height, const std::size_t _width);
            ~Matrix() = default;

            void identity();
            void reset(const T &_val = 0);

            std::vector<T> &operator[](std::size_t _n);
            const std::vector<T> &at(std::size_t _n) const;
            std::size_t getHeight() const;
            std::size_t getWidth() const;

            bool resize(const std::size_t _height, const std::size_t _width);
            bool checkIntegrity() const;

            void pointAt(const d3::Vectorf &_pos, const d3::Vectorf &_target, const d3::Vectorf &_vup);
        private:
            std::size_t m_height = 0;
            std::size_t m_width = 0;
            std::vector<std::vector<T>> m_mtr = {};
    };
}

template<typename T>
Maths::Matrix<T> operator*(const Maths::Matrix<T> &_fst, const Maths::Matrix<T> &_snd);
template<typename T>
d3::Vector<T> operator*(const Maths::Matrix<T> &_fst, const d3::Vector<T> &_snd);

#include "Matrix.inl"