/*
** DipStax 2021
** 3D-Engine
** File description:
** Camera.cpp
*/

#include "Engine/Camera.hpp"

namespace Engine {

    Camera::Camera(const d3::Pointf &_pos, const d3::Pointf &_target, const d3::Pointf &_vup)
        : m_pos(_pos), m_target(_target), m_vup(_vup), m_dir(0, 0, 0), m_mtr(4, 4)
    {
        calculate();
    }

    d3::Pointf Camera::getPosition() const
    {
        return m_pos;
    }

    Maths::Matrix<float> Camera::getMatrix() const
    {
        return m_mtr;
    }

    void Camera::setVUp(const d3::Pointf &_vup)
    {
        m_vup = _vup;
        calculate();
    }

    void Camera::setTarget(const d3::Pointf &_target)
    {
        m_target = _target;
        calculate();
    }

    void Camera::setPosition(const d3::Pointf &_pos)
    {
        m_pos = _pos;
        calculate();
    }

    void Camera::moveTarget(const d3::Pointf &_target)
    {
        m_target = m_target + _target;
        calculate();
    }

    void Camera::move(const d3::Pointf &_move)
    {
        m_pos = m_pos + _move;
        calculate();
    }


    void Camera::calculate()
    {
        d3::Vectorf target;

        m_dir = Maths::matrixRotationY(0) * d3::Vectorf(m_target);
        target = d3::Vectorf(m_pos) + m_dir;
        m_mtr.pointAt(m_pos, target, m_vup);
        m_mtr.quickInvert();
    }
}