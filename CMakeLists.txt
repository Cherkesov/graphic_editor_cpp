cmake_minimum_required(VERSION 3.3)
project(graphic_editor_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp Figure.cpp Figure.h TriangleFigure.cpp TriangleFigure.h Vector2.cpp Vector2.h Color.cpp Color.h RectangleFigure.cpp RectangleFigure.h)
add_executable(graphic_editor_cpp ${SOURCE_FILES})

ADD_DEFINITIONS(
        -lopengl32
        -lglu32
)

target_link_libraries(graphic_editor_cpp glut32.lib)