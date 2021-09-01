/*
** DipStax 2021
** 3D-Engine
** File description:
** Triangle.hpp
*/

#include "Engine/Triangle.hpp"
#include <iostream>

namespace Engine {

    Triangle::Triangle(const d3::Pointf &_fst, const d3::Pointf &_snd, const d3::Pointf &_thd)
        : m_vertex(sf::Triangles, 3)
    {
        m_pt[0] = _fst;
        m_pt[1] = _snd;
        m_pt[2] = _thd;
        m_vertex[0].color = sf::Color::Red;
        m_vertex[1].color = sf::Color::Blue;
        m_vertex[2].color = sf::Color::Green;
    }

    d3::Pointf Triangle::operator[](std::size_t _n)
    {
        return m_pt[_n];
    }

    bool Triangle::clip(const d3::Vectorf &_plann, const d3::Vectorf &_planp) const
    {
        float clip;
        d3::Vectorf plann_norm = _plann.normalise();
        float dotprod = plann_norm.dotProduct(_planp);

        for (int it = 0; it < 3; it++)
            clip += plann_norm.x * m_view_pt[it].x + plann_norm.y * m_view_pt[it].y + plann_norm.z * m_view_pt[it].z - dotprod;
        return clip >= 0;
    }

    void Triangle::transform(const d2::Vectorf &_size, const d3::Vectorf &_cam, const Maths::Matrix<float> &_world, const Maths::Matrix<float> &_view, const Maths::Matrix<float> &_proj)
    {
        d3::Vectorf normal;
        d3::Vectorf ray;
        d3::Vectorf pt_tmp[3];
        Maths::Matrix<float> mx = Maths::matrixRotationX(0);
        Maths::Matrix<float> mz = Maths::matrixRotationZ(0);

        for (int it = 0; it < 3; it++) {
            pt_tmp[it] =  mx * (mz * d3::Vectorf(m_pt[it]));
            pt_tmp[it].z += 3;
        }
        normal = d3::Vectorf(pt_tmp[1] - pt_tmp[0]).crossProduct(pt_tmp[2] - pt_tmp[0]).normalise();
        if (normal.x * (pt_tmp[0].x - _cam.x) + normal.y * (pt_tmp[0].y - _cam.y)
            + normal.z * (pt_tmp[0].z - _cam.z) < 0) {
            for (int it = 0; it < 3; it++) {
                m_view_pt[it] = _proj * (_view * d3::Vectorf(pt_tmp[it]));
                m_view_pt[it].x = (m_view_pt[it].x + 1) * 0.5 * _size.x;
                m_view_pt[it].y = (m_view_pt[it].y + 1) * 0.5 * _size.y;
                m_vertex[it].position = { m_view_pt[it].x, m_view_pt[it].y};
            }
            m_visible = true;
        } else {
            m_visible = false;
        }
    }

    void Triangle::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
    {
        if (!m_visible)
            return;
        _target.draw(m_vertex, _states);
    }
}