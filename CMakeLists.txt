cmake_minimum_required(VERSION 3.3)
project(launcher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif (NOT GLUT_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)


set(SOURCE_FILES
        main.cpp

        figure/AbstractFigure.h
        figure/RectangleFigure.h
        figure/CircleFigure.h
        figure/PolyLineFigure.h
        figure/LineFigure.h

        tool/AbstractTool.h
        tool/PencilTool.h
        tool/StraightLineTool.h

        Vector2.h
        Color.h
        )
add_executable(launcher ${SOURCE_FILES})

#add_executable(launcher main.cpp)

target_link_libraries(launcher ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})