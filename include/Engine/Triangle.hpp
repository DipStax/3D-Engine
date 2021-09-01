/*
** DipStax 2021
** 3D-Engine
** File description:
** Triangle.hpp
*/

#pragma once

#include "Render.hpp"
#include "2D/Vector.hpp"
#include "3D/Point.hpp"
#include "3D/Vector.hpp"
#include "Maths/Matrix.hpp"
#include "Maths/matrix_gen.hpp"

namespace Engine {

    class Triangle : public Render {
        public:
            Triangle(const d3::Pointf &_fst, const d3::Pointf &_snd, const d3::Pointf &_thd);
            ~Triangle() = default;

            [[nodiscard]] d3::Pointf operator[](std::size_t _n);

            [[nodiscard]] bool clip(const d3::Vectorf &_plann, const d3::Vectorf &_planp) const;
            void transform(const d2::Vectorf &_size, const d3::Vectorf &_cam, const Maths::Matrix<float> &_world, const Maths::Matrix<float> &_view, const Maths::Matrix<float> &_proj);
            void calculLight(const d3::Vectorf &_light);

        protected:
            virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;
        private:
            d3::Pointf m_pt[3];
            d3::Vectorf m_view_pt[3];
            bool m_visible = false;
            sf::VertexArray m_vertex;
            d3::Vectorf m_normal;
    };
}