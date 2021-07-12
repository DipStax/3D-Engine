set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

if (UNIX)
	add_compile_options(-Wall -Wextra -Weffc++ -std=c++17)
else ()
	add_compile_options(/W4 /std:c++17)
endif ()

set(SOURCES
	src/Engine/Camera.cpp
	src/Engine/Mesh.cpp
	src/Engine/Triangle.cpp
	src/Maths/Matrix_gen.cpp
	src/main.cpp
	)
set(INCLUDES
	include/3D/Point.hpp
	include/3D/Point.inl
	include/3D/Vector.hpp
	include/3D/Vector.inl
	include/Engine/Camera.hpp
	include/Engine/Mesh.hpp
	include/Engine/Triangle.hpp
	include/Maths/Matrix_gen.hpp
	include/Maths/Matrix.hpp
	include/Maths/Matrix.inl
)

add_executable(3D-Engine
	${SOURCES}
	${INCLUDES}
)

foreach(source IN LISTS SOURCES)
	get_filename_component(source_path "${source}" PATH)
	string(REPLACE "/" "\\" source_path_msvc "${source_path}")
	source_group("${source_path_msvc}" FILES "${source}")
endforeach()

foreach(include IN LISTS INCLUDES)
	get_filename_component(include_path "${include}" PATH)
	string(REPLACE "/" "\\" include_path_msvc "${include_path}")
	source_group("${include_path_msvc}" FILES "${include}")
endforeach()

target_link_libraries(3D-Engine PRIVATE sfml-graphics sfml-audio sfml-network sfml-system)
target_include_directories(3D-Engine PRIVATE include)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT 3D-Engine)