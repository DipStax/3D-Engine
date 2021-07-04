/*
** DipStax 2021
** 3D-Engine
** File description:
** main
*/

#include <iostream>
#include "3D/Point.hpp"
#include "3D/Vector.hpp"

int main()
{
    d3::Pointi pti2(1, 2, 3);
    d3::Pointi pti1(2, 3, 4);

    d3::Pointi ptr = pti1 - pti2;

    d3::Vectori vec1(1, 2, 3);
    d3::Vectori vec2(2, 3, 4);

    d3::Vectori vec = vec1 - vec2;
    std::cout << "run" << std::endl;
    return 0;
}