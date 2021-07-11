/*
** DipStax 2021
** 3D-Engine
** File description:
** Matrix.inl
*/

#include "Matrix.hpp"

namespace Maths {

    template<typename T>
    Matrix<T>::Matrix(const size_t _height, const size_t _width)
    {
        m_mtr.resize(_height);
        for (std::vector<T> vec : m_mtr)
            vec.resize(_width);
        m_height = _height;
        m_width = _width;
    }

    template<typename T>
    std::vector<T> &Matrix<T>::operator[](size_t _n)
    {
        return m_mtr.at(_n);
    }

    template<typename T>
    std::vector<T> &Matrix<T>::at(size_t _n)
    {
        return m_mtr.at(_n);
    }

    template<typename T>
    bool Matrix<T>::resize(const size_t _height, const size_t _width)
    {
        if (!checkIntegrity())
            return false;
        m_mtr.resize(_height);
        for (std::vector<T> vec : m_mtr)
            vec.resize(_width);
        m_height = _height;
        m_width = _width;
        return true;
    }

    template<typename T>
    bool Matrix<T>::checkIntegrity() const
    {
        if (m_mtr.size() != m_height)
            return false;
        for (std::vector<T> vec : m_mtr)
            if (vec.size() != m_width)
                return false;
        return true;
    }
}

template<typename T>
Maths::Matrix<T> operator*(const Maths::Matrix<T> &_fst, const Maths::Matrix<T> &_snd)
{
    Maths::Matrix<T> mtr(_fst.getHeight(), _fst.getWidth());

    if (_fst.getHeight() != _snd.getHeight() || _fst.getWidth() != _snd.getWidth())
        throw ("[Matrix::*]: can't multiply differente size of matrix");
    for (int x = 0; x < _fst.getHeight(); x++)
        for (int y = 0; y < _fst.getHeight(); y++)
            mtr.m[y][x] = _fst[y][0] * _snd[0][x] + _fst[y][1] * _snd[1][x] + _fst[y][2] * _snd[2][x] + _fst[y][3] * _snd[3][x];
    return mtr;
}