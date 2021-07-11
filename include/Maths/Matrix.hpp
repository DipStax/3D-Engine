/*
** DipStax 2021
** 3D-Engine
** File description:
** Matrix.hpp
*/

#pragma once

#include <vector>

namespace Maths {

    template<typename T>
    class Matrix {
        public:
            Matrix(const size_t _height, size_t _width);
            ~Matrix() = default;

            void identity();

            std::vector<T> &operator[](size_t _n);
            std::vector<T> &at(size_t _n);
            size_t getHeight() const;
            size_t getWidth() const;

            bool resize(const size_t _height, const size_t _width);
            bool checkIntegrity() const;
        private:
            size_t m_height;
            size_t m_width;
            std::vector<std::vector<T>> m_mtr;
    };
}

template<typename T>
Maths::Matrix<T> operator*(const Maths::Matrix<T> &_fst, const Maths::Matrix<T> &_snd);

#include "Matrix.inl"