/*
** DipStax 2021
** 3D-Engine
** File description:
** matrix_gen.hpp
*/

#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"

namespace Maths {

    Matrix<float> matrixRotationX(const float _rot);
    Matrix<float> matrixRotationY(const float _rot);
    Matrix<float> matrixRotationZ(const float _rot);

    Matrix<float> matrixTranslation(const d3::Vectorf &_vec);
}