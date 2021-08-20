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
    {
        m_pt[0] = _fst;
        m_pt[1] = _snd;
        m_pt[2] = _thd;
        for (int it = 0; it < 4; it++)
            m_vertex[it].color = sf::Color::Black;
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

        std::cout << "- - - Transforme - - -" << std::endl;
        for (int it = 0; it < 3; it++) {
            std::cout << "[" << it <<  "] start:\t\t" << m_view_pt[it].x << " | " << m_view_pt[it].y << " | " << m_view_pt[it].z << " <> " << m_pt[it].x << " | " << m_pt[it].y << " | " << m_pt[it].z << std::endl;
            m_view_pt[it] = _proj * d3::Vectorf(m_pt[it]);
            std::cout << "[" << it <<  "] projection:\t\t" << m_view_pt[it].x << " | " << m_view_pt[it].y << " | " << m_view_pt[it].z << std::endl;
            m_view_pt[it].x += 1;
            m_view_pt[it].y += 1;
            std::cout << "[" << it <<  "] add:\t\t" << m_view_pt[it].x << " | " << m_view_pt[it].y << " | " << m_view_pt[it].z << std::endl;
            m_view_pt[it].x *= 0.5 * _size.x;
            m_view_pt[it].y *= 0.5 * _size.y;
            m_vertex[it].position = { m_view_pt[it].x - 100.f, m_view_pt[it].y - 200.f };
            std::cout << "[" << it <<  "] end:\t\t" << m_view_pt[it].x << " | " << m_view_pt[it].y << " | " << m_view_pt[it].z << std::endl;
        }
        m_vertex[3].position = m_vertex[0].position;

        /*normal = (m_view_pt[1] - m_view_pt[0]).crossProduct(m_view_pt[2] - m_view_pt[0]).normalise();
        ray = m_view_pt[0] - _cam;

        m_visible = normal.dotProduct(ray) < 0.f;
        if (!m_visible)
            return;
        for (int it = 0; it < 3; it++)
            m_view_pt[it] = _view * m_view_pt[it];

        // error for clip check
        m_visible = clip(d3::Vectorf(0, 0, 1), d3::Vectorf(0, 0, 1));
        if (!m_visible)
            return;
        for (int it = 0; it < 3; it++) {
            m_view_pt[it] = (_proj * m_view_pt[it]) / m_view_pt[it].w;
            m_view_pt[it].x *= -1;
            m_view_pt[it].y *= -1;
            m_view_pt[it] = m_view_pt[it] + d3::Vectorf(1, 1, 0);
            m_view_pt[it].x *= 0.5 * _size.x;
            m_view_pt[it].y *= 0.5 * _size.y;
            m_vertex[it].position = { m_view_pt[it].x, m_view_pt[it].y };
        }*/
    }

    void Triangle::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
    {
        /*if (!m_visible)
            return;*/
        std::cout << "draw tri" << std::endl;
        for (int it = 0; it < 4; it++) {
            std::cout << "[" << it <<  "] end:\t\t" << m_vertex[it].position.x << " | " << m_vertex[it].position.y << std::endl;
        }
        _target.draw(m_vertex, 4, sf::LinesStrip, _states);
    }
}