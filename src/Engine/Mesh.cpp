/*
** DipStax 2021
** 3D-Engine
** File description:
** Mesh.cpp
*/

#include "Engine/Mesh.hpp"

#include <fstream>
#include <sstream>

namespace Engine {

    void Mesh::clear()
    {
        m_tri.clear();
    }

    const Triangle &Mesh::at(std::size_t _n) const
    {
        return m_tri.at(_n);
    }

    Triangle &Mesh::operator[](std::size_t _n)
    {
        return m_tri[_n];
    }

    void Mesh::load(const std::string &_path)
    {
        std::ifstream file(_path);
        std::istringstream stream;
        std::string line;
        std::string trash;
        std::vector<d3::Pointf> vec;
        d3::Pointf tmp;
        int tab[3];

        if (!file)
            throw ("[Mesh::load]: (_path) is inaccessible: " + _path);
        while (!file.eof()) {
            std::getline(file, line);
            stream.str(line);

            if (line[0] == 'v') {
                stream >> trash >> tmp.x >> tmp.y >> tmp.z;
                vec.push_back(tmp);
            } else if (line[0] == 'f') {
                stream >> trash >> tab[0] >> tab[1] >> tab[2];
                m_tri.emplace_back(vec.at(tab[0] - 1), vec.at(tab[1] - 1), vec.at(tab[2] - 1));
            }
            stream.clear();
            line.clear();
        }
    }

    void Mesh::setModel(Model _model)
    {
        switch (_model) {
            case Model::CUBE:       cube();
                break;
            case Model::PYRAMID:    pyramid();
                break;
        }
    }

    void Mesh::cube()
    {
        clear();

        // front
        m_tri.emplace_back(d3::Pointf{ 0, 0, 0 }, d3::Pointf{ 0, 1, 0 }, d3::Pointf{ 1, 0, 0 });
        m_tri.emplace_back(d3::Pointf{ 1, 0, 0 }, d3::Pointf{ 0, 1, 0 }, d3::Pointf{ 1, 1, 0 });

        // back
        m_tri.emplace_back(d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 0, 1, 1 }, d3::Pointf{ 1, 0, 1 });
        m_tri.emplace_back(d3::Pointf{ 1, 0, 1 }, d3::Pointf{ 0, 1, 1 }, d3::Pointf{ 1, 1, 1 });

        // top
        m_tri.emplace_back(d3::Pointf{ 0, 1, 0 }, d3::Pointf{ 1, 1, 0 }, d3::Pointf{ 0, 1, 1 });
        m_tri.emplace_back(d3::Pointf{ 0, 1, 0 }, d3::Pointf{ 0, 1, 1 }, d3::Pointf{ 1, 1, 1 });

        // down
        m_tri.emplace_back(d3::Pointf{ 0, 0, 0 }, d3::Pointf{ 1, 0, 0 }, d3::Pointf{ 0, 0, 1 });
        m_tri.emplace_back(d3::Pointf{ 0, 0, 0 }, d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 1, 0, 1 });

        // left
        m_tri.emplace_back(d3::Pointf{ 0, 0, 0 }, d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 0, 1, 0 });
        m_tri.emplace_back(d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 0, 1, 1 }, d3::Pointf{ 0, 0, 1 });

        // right
        m_tri.emplace_back(d3::Pointf{ 1, 0, 0 }, d3::Pointf{ 1, 0, 1 }, d3::Pointf{ 1, 1, 0 });
        m_tri.emplace_back(d3::Pointf{ 1, 0, 1 }, d3::Pointf{ 1, 1, 1 }, d3::Pointf{ 1, 0, 1 });
    }

    void Mesh::pyramid()
    {
        clear();

        // down
        m_tri.emplace_back(d3::Pointf{ 0, 0, 0 }, d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 0, 1, 0 });
        m_tri.emplace_back(d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 0, 1, 1 }, d3::Pointf{ 0, 1, 0 });

        // top
        m_tri.emplace_back(d3::Pointf{ 0, 0, 0 }, d3::Pointf{ 0.5, 1, 0.5 }, d3::Pointf{ 1, 0, 0 });
        m_tri.emplace_back(d3::Pointf{ 0, 0, 1 }, d3::Pointf{ 0.5, 1, 0.5 }, d3::Pointf{ 0, 0, 0 });
        m_tri.emplace_back(d3::Pointf{ 1, 0, 1 }, d3::Pointf{ 0.5, 1, 0.5 }, d3::Pointf{ 0, 0, 1 });
        m_tri.emplace_back(d3::Pointf{ 1, 0, 0 }, d3::Pointf{ 0.5, 1, 0.5 }, d3::Pointf{ 1, 0, 1 });
    }

    void Mesh::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
    {
        for (auto &_tri : m_tri)
            _target.draw(_tri, _states);
    }

    std::vector<Triangle> &Mesh::getTriangle()
    {
        return m_tri;
    }
}