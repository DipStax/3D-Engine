/*
** DipStax 2021
** 3D-Engine
** File description:
** matrix_gen.cpp
*/

#include "Maths/matrix_gen.hpp"

namespace Maths {

    Matrix<float> matrixRotationX(const float _rot)
    {
        Matrix<float> mtr(4, 4);

        mtr[0][0] = 1.0f;
        mtr[1][1] = cosf(_rot);
        mtr[1][2] = sinf(_rot);
        mtr[2][1] = -sinf(_rot);
        mtr[2][2] = cosf(_rot);
        mtr[3][3] = 1.0f;
        return mtr;
    }

    Matrix<float> matrixRotationY(const float _rot)
    {
        Matrix<float> mtr(4, 4);

        mtr[0][0] = cosf(_rot);
        mtr[0][2] = sinf(_rot);
        mtr[2][0] = -sinf(_rot);
        mtr[1][1] = 1.0f;
        mtr[2][2] = cosf(_rot);
        mtr[3][3] = 1.0f;
        return mtr;
    }

    Matrix<float> matrixRotationZ(const float _rot)
    {
        Matrix<float> mtr(4, 4);

        mtr[0][0] = cosf(_rot);
        mtr[0][1] = sinf(_rot);
        mtr[1][0] = -sinf(_rot);
        mtr[1][1] = cosf(_rot);
        mtr[2][2] = 1.0f;
        mtr[3][3] = 1.0f;
        return mtr;
    }

    Matrix<float> matrixTranslation(const d3::Vectorf &_vec)
    {
        Matrix<float> mtr(4, 4);

        mtr[0][0] = 1.0f;
        mtr[1][1] = 1.0f;
        mtr[2][2] = 1.0f;
        mtr[3][3] = 1.0f;
        mtr[3][0] = _vec.x;
        mtr[3][1] = _vec.y;
        mtr[3][2] = _vec.z;
        return mtr;
    }

    Matrix<float> matrixProjection(const float &_fov, const float &_ar, const float &_near, const float &_far)
    {
        Matrix<float> mtr(4, 4);
        float fovr = 1.f / tanf(_fov * 0.5f / 180.f * 3.14159f);

        std::cout << "ar: " << _ar << std::endl;
        mtr[0][0] = _ar * fovr;
        mtr[1][1] = fovr;
        mtr[2][2] = _far / (_far - _near);
        mtr[3][2] = (-_far * _near) / (_far - _near);
        mtr[2][3] = 1;
        return mtr;
    }
}