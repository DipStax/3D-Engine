cmake_minimum_required(VERSION 3.11)

find_package(sfml QUIET)
include(FetchContent)

set(sfml_VERSION 2.5.1)

FetchContent_Declare(
    sfml
    URL "https://github.com/SFML/SFML/archive/${sfml_VERSION}.zip"
)
FetchContent_GetProperties(sfml)