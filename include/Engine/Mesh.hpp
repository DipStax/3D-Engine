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

    class Mesh : public Render {

        public:
            enum class Model {
                CUBE,
                PYRAMID
            };

            Mesh() = default;
            ~Mesh() = default;

            void clear();

            [[nodiscard]] const Triangle &at(std::size_t _n) const;
            [[nodiscard]] Triangle &operator[](std::size_t _n);

            void load(const std::string &_obj);
            void setModel(Model _model);

        protected:
            friend class D3Instance;
            [[nodiscard]] std::vector<Triangle> &getTriangle();

        private:
            void cube();
            void pyramid();

            virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;


            std::vector<Triangle> m_tri;
    };
}