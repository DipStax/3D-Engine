/*
** DipStax 2021
** 3D-Engine
** File description:
** main
*/

#include <iostream>
#include "3D/Point.hpp"

int main()
{
    d3::Pointi pti2(1, 2, 3);
    d3::Pointi pti1(2, 3, 4);

    d3::Pointi ptr = pti1 - pti2;
    std::cout << "run" << std::endl;
    return 0;
}