/*
** DipStax 2021
** 3D-Engine
** File description:
** main
*/

#include <iostream>
#include "Engine/D3Instance.hpp"

int main()
{
    try {
        std::cout << "run" << std::endl;
        Engine::D3Instance instance("test", { 500, 400 });
        Engine::Camera cam({0, 5, 5});
        Engine::Mesh mesh;
        std::string str;

        mesh.setModel(Engine::Mesh::Model::PYRAMID);
        while (instance.isOpen()) {
            std::cout << "> reset" << std::endl;
            instance.reset();
            std::cout << "| refresh" << std::endl;
            instance.refresh(cam, mesh);
            std::cout << "| render" << std::endl;
            instance.render(mesh);
            std::cout << "< display" << std::endl;
            instance.display();
            std::cout << ">> new frame" << std::endl;
            std::cin >> str;
        }
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    return 0;
}