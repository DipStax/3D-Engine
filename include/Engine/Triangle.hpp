/*
** DipStax 2021
** 3D-Engine
** File description:
** Triangle.hpp
*/

#pragma once

#include "3D/Point.hpp"

namespace Engine {

    class Triangle {
        public:
            Triangle(const d3::Pointf &_fst, const d3::Pointf &_snd, const d3::Pointf &_thd);
            ~Triangle() = default;

            d3::Pointf operator[](std::size_t _n);

        private:
            d3::Pointf m_pt[3];
    };
}