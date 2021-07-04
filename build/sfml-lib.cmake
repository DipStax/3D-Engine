cmake_minimum_required(VERSION 3.11)

find_package(sfml QUIET)

set(sfml_VERSION 2.5.1)

if (NOT sfml_FOUND)
    include(FetchContent)

    FetchContent_Declare(
        sfml
        URL "https://github.com/SFML/SFML/archive/${sfml_VERSION}.zip"
    )
    FetchContent_GetProperties(sfml)
    if (NOT sfml_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(sfml)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})

        set(sfml_FOUND TRUE)

    endif()
endif()