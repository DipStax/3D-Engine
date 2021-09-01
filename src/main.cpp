/*
** DipStax 2021
** 3D-Engine
** File description:
** main
*/

#include <iostream>
#include "Engine/D3Instance.hpp"
#include <Windows.h>

int main()
{
    try {
        std::cout << "run" << std::endl;
        Engine::D3Instance instance("test", { 500, 400 });
        Engine::Camera cam({2, 2, -3}, {0, 0, 1});
        Engine::Mesh mesh;
        std::string str;

        mesh.setModel(Engine::Mesh::Model::CUBE);
        while (instance.isOpen()) {
            instance.reset();
            instance.refresh(cam, mesh);
            instance.render(mesh);
            instance.display();
            Sleep(100);
        }
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    return 0;
}