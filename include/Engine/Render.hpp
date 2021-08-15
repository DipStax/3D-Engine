/*
** DipStax 2021
** 3D-Engine
** File description:
** Render.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace Engine {

    class Render : public sf::Drawable {
        protected:
            friend class D3Instance;
            virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;
    };
}