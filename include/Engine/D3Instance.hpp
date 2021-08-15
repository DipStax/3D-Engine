/*
** DipStax 2021
** 3D-Engine
** File description:
** D3Instance.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Camera.hpp"
#include "Mesh.hpp"
#include "Maths/Matrix.hpp"

namespace Engine {

    class D3Instance {
        public:
            D3Instance(const std::string &_title, const d2::Vectoru &_size);
            virtual ~D3Instance();

            void refresh(const Camera &_cam, Mesh &_mesh);
            void refresh(const Camera &_cam, Triangle &_tri);

            void reset();
            void render(const Render &_rdr);
            void display();

            [[nodiscard]] bool isOpen() const;

            void close();
        private:
            void update();

            d2::Vectorf m_size;
            sf::RenderWindow m_win;
            Maths::Matrix<float> m_world;
            Maths::Matrix<float> m_proj;
    };
}