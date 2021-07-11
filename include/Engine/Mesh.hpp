/*
** DipStax 2021
** 3D-Engine
** File description:
** Mesh.hpp
*/

#pragma once

#include <vector>
#include <string>

#include "Engine/Triangle.hpp"

namespace Engine {

    class Mesh {

        enum class Model {
            CUBE,
            PYRAMID
        };

        public:
            Mesh() = default;
            ~Mesh() = default;

            void clear();

            Triangle &at(size_t _n);
            Triangle &operator[](size_t _n);

            void load(const std::string &_obj);
            void setModel(Model _model);

        private:
            void cube();
            void pyramid();

            std::vector<Triangle> m_tri;
    };
}