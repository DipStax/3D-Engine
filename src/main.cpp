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
        Engine::Camera cam({0, 0, 0}, {0, 0, 1});
        Engine::Mesh mesh;
        std::string str;

        mesh.setModel(Engine::Mesh::Model::CUBE);
        while (instance.isOpen()) {
            cam.move({0.1, 0, 0});
            std::cout << "> reset" << std::endl;
            instance.reset();
            std::cout << "| refresh" << std::endl;
            instance.refresh(cam, mesh);
            std::cout << "| render" << std::endl;
            instance.render(mesh);
            std::cout << "< display" << std::endl;
            instance.display();
            std::cout << ">> new frame" << std::endl;
            Sleep(100);
        }
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    return 0;
}