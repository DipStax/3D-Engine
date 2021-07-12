/*
** DipStax 2021
** 3D-Engine
** File description:
** Triangle.hpp
*/

#include "Engine/Triangle.hpp"

namespace Engine {

    Triangle::Triangle(const d3::Pointf &_fst, const d3::Pointf &_snd, const d3::Pointf &_thd)
    {
        m_pt[0] = _fst;
        m_pt[1] = _snd;
        m_pt[2] = _thd;
    }

    d3::Pointf Triangle::operator[](std::size_t _n)
    {
        return m_pt[_n];
    }
}