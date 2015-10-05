# Graphic Editor Cpp

Build project with MinGW (at first you should install glut and freeglut for MinGW)

    $ g++ -o main -Wall main.cpp Figure.cpp Figure.h TriangleFigure.cpp TriangleFigure.h Point.cpp Point.h Color.cpp Color.h -mwindows -lopengl32 -lglu32 -lfreeglut && main
