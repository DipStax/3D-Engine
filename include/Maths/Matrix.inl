/*
** DipStax 2021
** 3D-Engine
** File description:
** Matrix.inl
*/

#include "Matrix.hpp"

namespace Maths {

    template<typename T>
    Matrix<T>::Matrix(const std::size_t _height, const std::size_t _width)
    {
        resize(_height, _width);
    }

    template<typename T>
    void Matrix<T>::identity()
    {
        reset();
        for (std::size_t y = 0; y < m_height; y++)
            for (std::size_t x = 0; x < m_height; x++)
                if (y == x)
                    m_mtr[y][x] = 1;
    }

    template<typename T>
    void Matrix<T>::reset(const T &_val)
    {
        for (auto &_line : m_mtr)
            for (T &_case : _line)
                _case = _val;
    }

    template<typename T>
    std::vector<T> &Matrix<T>::operator[](std::size_t _n)
    {
        return m_mtr.at(_n);
    }

    template<typename T>
    const std::vector<T> &Matrix<T>::at(std::size_t _n) const
    {
        return m_mtr.at(_n);
    }

    template<typename T>
    std::size_t Matrix<T>::getHeight() const
    {
        return m_height;
    }

    template<typename T>
    std::size_t Matrix<T>::getWidth() const
    {
        return m_width;
    }

    template<typename T>
    void Matrix<T>::quickInvert()
    {
        m_mtr[0][0] = m_mtr[0][0];    m_mtr[0][1] = m_mtr[1][0];    m_mtr[0][2] = m_mtr[2][0];    m_mtr[0][3] = 0.0f;
        m_mtr[1][0] = m_mtr[0][1];    m_mtr[1][1] = m_mtr[1][1];    m_mtr[1][2] = m_mtr[2][1];    m_mtr[1][3] = 0.0f;
        m_mtr[2][0] = m_mtr[0][2];    m_mtr[2][1] = m_mtr[1][2];    m_mtr[2][2] = m_mtr[2][2];    m_mtr[2][3] = 0.0f;
        m_mtr[3][0] = -(m_mtr[3][0] * m_mtr[0][0] + m_mtr[3][1] * m_mtr[1][0] + m_mtr[3][2] * m_mtr[2][0]);
        m_mtr[3][1] = -(m_mtr[3][0] * m_mtr[0][1] + m_mtr[3][1] * m_mtr[1][1] + m_mtr[3][2] * m_mtr[2][1]);
        m_mtr[3][2] = -(m_mtr[3][0] * m_mtr[0][2] + m_mtr[3][1] * m_mtr[1][2] + m_mtr[3][2] * m_mtr[2][2]);
        m_mtr[3][3] = 1.0f;
    }

    template<typename T>
    void Matrix<T>::resize(const std::size_t _height, const std::size_t _width)
    {

        m_mtr.resize(_height);
        for (std::vector<T> &vec : m_mtr)
            vec.resize(_width);
        m_height = _height;
        m_width = _width;
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

    template<typename T>
    void Matrix<T>::pointAt(const d3::Vectorf &_pos, const d3::Vectorf &_target, const d3::Vectorf &_vup)
    {
        if (m_height != 4 || m_width != 4)
            throw ("[Matrix::pointAt]: wrong size matrix");
        d3::Vectorf forward = (_target - _pos).normalise();
        d3::Vectorf vup = (_vup - forward * forward.dotProduct(_vup)).normalise();
        d3::Vectorf right = vup.crossProduct(forward);

        reset();
        m_mtr[0][0] = right.x;  m_mtr[0][1] = right.y;  m_mtr[0][2] = right.z;
        m_mtr[1][0] = vup.x;    m_mtr[1][1] = vup.y;    m_mtr[1][2] = vup.z;
        m_mtr[2][0] = forward.x;m_mtr[2][1] = forward.y;m_mtr[2][2] = forward.z;
        m_mtr[3][0] = _pos.x;   m_mtr[3][1] = _pos.y;   m_mtr[3][2] = _pos.z;
        m_mtr[3][3] = 1;
    }
}

template<typename T>
Maths::Matrix<T> operator*(const Maths::Matrix<T> &_fst, const Maths::Matrix<T> &_snd)
{
    Maths::Matrix<T> mtr(_fst.getHeight(), _fst.getWidth());

    if (_fst.getHeight() != _snd.getHeight() || _fst.getWidth() != _snd.getWidth())
        throw ("[Matrix::*]: can't multiply differente size of matrix");
    if (_fst.getHeight() != _fst.getWidth())
        throw ("[Matrix::*]: can't multiply non square matrix");
    for (std::size_t x = 0; x < _fst.getWidth(); x++)
        for (std::size_t y = 0; y < _fst.getHeight(); y++) {
            mtr[y][x] = 0;
            for (std::size_t it = 0; it < _fst.getWidth(); it++)
                mtr[y][x] += _fst.at(y)[it] * _snd.at(it)[x];
        }
    return mtr;
}

template<typename T>
d3::Vector<T> operator*(const Maths::Matrix<T> &_fst, const d3::Vector<T> &_snd)
{
    d3::Vector<T> vec;

    if (_fst.getHeight() != 4 || _fst.getWidth() != 4)
        throw ("[Matrix::*]: can't multiply non 4*4 matrix with d3::Vector");
    vec.x = _snd.x * _fst.at(0)[0] + _snd.y * _fst.at(1)[0] + _snd.z * _fst.at(2)[0] + _fst.at(3)[0];
    vec.y = _snd.x * _fst.at(0)[1] + _snd.y * _fst.at(1)[1] + _snd.z * _fst.at(2)[1] + _fst.at(3)[1];
    vec.z = _snd.x * _fst.at(0)[2] + _snd.y * _fst.at(1)[2] + _snd.z * _fst.at(2)[2] + _fst.at(3)[2];
    vec.w = _snd.x * _fst.at(0)[3] + _snd.y * _fst.at(1)[3] + _snd.z * _fst.at(2)[3] + _fst.at(3)[3];
    if (vec.w != 0) {
        vec.x /= vec.w;
        vec.y /= vec.w;
        vec.z /= vec.w;
    }
    return vec;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Maths::Matrix<T> &_mtr)
{
    for (std::size_t y = 0; y < _mtr.getHeight(); y++) {
        for (std::size_t x = 0; x < _mtr.getHeight(); x++)
            os << "[" << _mtr.at(y).at(x) << "]\t";
        os << std::endl;
    }
    return os;
}