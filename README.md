# Graphic Editor Cpp

Build project with MinGW (at first you should install glut and freeglut for MinGW)

    $ g++ -o main -Wall main.cpp Figure.cpp Figure.h TriangleFigure.cpp TriangleFigure.h Vector2.cpp Vector2.h Color.cpp Color.h RectangleFigure.cpp RectangleFigure.h -mwindows -lopengl32 -lglu32 -lfreeglut && main
