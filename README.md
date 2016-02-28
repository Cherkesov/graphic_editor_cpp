# Graphic Editor Cpp

Build project with MinGW (at first you should install glut and freeglut for MinGW)

    $ g++ -o main -Wall main.cpp Figure.h TriangleFigure.h Vector2.h Color.h RectangleFigure.h CircleFigure.h -mwindows -lopengl32 -lglu32 -lfreeglut && main
