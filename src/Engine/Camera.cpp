/*
** DipStax 2021
** 3D-Engine
** File description:
** Camera.cpp
*/

#include "Engine/Camera.hpp"

namespace Engine {

    Camera::Camera(const d3::Pointf &_pos, const d3::Pointf &_target, const d3::Pointf &_vup)
        : m_pos(_pos), m_target(_target), m_vup(_vup)
    {
        calculate();
    }

    void Camera::calculate()
    {
        d3::Vectorf target = (Maths::matrixRotationY(0) * d3::Vectorf(m_target)) + d3::Vectorf(m_pos);
        Maths::Matrix<float> mtr(4, 4);

        mtr.pointAt(m_pos, target, m_vup);
    }
}