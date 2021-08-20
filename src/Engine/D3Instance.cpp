/*
** DipStax 2021
** 3D-Engine
** File description:
** D3Instance.cpp
*/

#include "Engine/D3Instance.hpp"

namespace Engine {

    D3Instance::D3Instance(const std::string &_title, const d2::Vectoru &_size)
        : m_size(static_cast<float>(_size.x), static_cast<float>(_size.y)), m_win({ _size.x, _size.y }, _title), m_world(4, 4), m_proj(4, 4)
    {
        m_proj = Maths::matrixProjection(90, static_cast<float>(_size.y) / static_cast<float>(_size.x), 0.1, 1000);
        std::cout << m_proj << std::endl;
    }

    D3Instance::~D3Instance()
    {
        close();
    }


    void D3Instance::refresh(const Camera &_cam, Mesh &_mesh)
    {
        for (Triangle &_tri : _mesh.getTriangle())
            refresh(_cam, _tri);
    }

    void D3Instance::refresh(const Camera &_cam, Triangle &_tri)
    {
        _tri.transform(m_size, _cam.getPosition(), m_world, _cam.getMatrix(), m_proj);
    }

    void D3Instance::reset()
    {
        m_win.clear(sf::Color::White);
        update();
    }

    void D3Instance::render(const Render &_rdr)
    {
        m_win.draw(_rdr);
    }

    void D3Instance::display()
    {
        m_win.display();
    }

    bool D3Instance::isOpen() const
    {
        return m_win.isOpen();
    }

    void D3Instance::close()
    {
        if (m_win.isOpen())
            m_win.close();
    }

    void D3Instance::update()
    {
        m_world = Maths::matrixRotationX(0) * Maths::matrixRotationY(0) * Maths::matrixTranslation(d3::Vectorf(0, 0, 5));
    }
}