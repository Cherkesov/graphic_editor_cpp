cmake_minimum_required(VERSION 3.3)
project(graphic_editor_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp
        figure/AbstractFigure.h
        figure/RectangleFigure.h
        figure/CircleFigure.h
        figure/PolyLineFigure.h

        tool/AbstractTool.h
        tool/PencilTool.h

        Vector2.h
        Color.h
        )
add_executable(graphic_editor_cpp ${SOURCE_FILES})

ADD_DEFINITIONS(
        -mwindows
        -lopengl32
        -lglu32
        -lfreeglut
)

#target_link_libraries(graphic_editor_cpp glut32.lib)