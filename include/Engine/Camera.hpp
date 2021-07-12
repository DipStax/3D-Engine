/*
** DipStax 2021
** 3D-Engine
** File description:
** Camera
*/

#pragma once

#include "3D/Vector.hpp"
#include "Maths/Matrix_gen.hpp"

namespace Engine {
    class Camera {
        public:
            Camera(const d3::Pointf &_pos, const d3::Pointf &_target = d3::Pointf{ 0, 0, 0 }, const d3::Pointf &_vup = d3::Pointf{ 0, 1, 0 });
            ~Camera() = default;

            void setVUp(const d3::Pointf &_vup = d3::Pointf{ 0, 1, 0 });
            void setTarget(const d3::Pointf &_target);
            void setPosition(const d3::Pointf &_pos);

            void moveTarget(const d3::Pointf &_target);
            void move(const d3::Pointf &_move);

        private:
            void calculate();

            d3::Pointf m_pos;
            d3::Pointf m_target;
            d3::Pointf m_vup;
    };
}