#define GLUT_DISABLE_ATEXIT_HACK

#ifdef _WIN32

#include <windows.h>

#endif

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>

#include "TriangleFigure.h"
#include "RectangleFigure.h"

using namespace std;

TriangleFigure *triangleFigure1 = new TriangleFigure(
        new Vector2(0.1f, -0.6f),
        new Vector2(0.7f, -0.6f),
        new Vector2(0.4f, -0.1f),
        new Color(0.0f, 0.0f, 1.0f)
);

RectangleFigure *rectangleFigure1 = new RectangleFigure(
        new Vector2(0.0f, -0.0f),
        new Vector2(0.5f, -0.5f),
        new Color(0.0f, 1.0f, 1.0f)
);

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    /*glBegin(GL_QUADS);
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, 0.1f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.2f, 0.7f);
        glVertex2f(-0.8f, 0.7f);

        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex2f(-0.7f, -0.6f);
        glVertex2f(-0.1f, -0.6f);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex2f(-0.9f, -0.7f);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(-0.5f, -0.7f);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex2f(-0.5f, -0.3f);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(-0.9f, -0.3f);
    }
    glEnd();*/
    rectangleFigure1->render();

//    glBegin(GL_TRIANGLES);            // Each set of 3 vertices form a triangle
//    {
//        glColor3f(0.0f, 0.0f, 1.0f); // Blue
//        glVertex2f(0.1f, -0.6f);
//        glVertex2f(0.7f, -0.6f);
//        glVertex2f(0.4f, -0.1f);
//
//        glColor3f(1.0f, 0.0f, 0.0f); // Red
//        glVertex2f(0.3f, -0.4f);
//        glColor3f(0.0f, 1.0f, 0.0f); // Green
//        glVertex2f(0.9f, -0.4f);
//        glColor3f(0.0f, 0.0f, 1.0f); // Blue
//        glVertex2f(0.6f, -0.9f);
//    }
//    glEnd();

    triangleFigure1->render();

//    glBegin(GL_POLYGON);                // These vertices form a closed polygon
//    {
//        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//        glVertex2f(0.4f, 0.2f);
//        glVertex2f(0.6f, 0.2f);
//        glVertex2f(0.7f, 0.4f);
//        glVertex2f(0.6f, 0.6f);
//        glVertex2f(0.4f, 0.6f);
//        glVertex2f(0.3f, 0.4f);
//    }
//    glEnd();

    glFlush();  // Render now
}

// Keyboard method to allow ESC key to quit
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char **argv) {
    /*triangleFigure1 = new TriangleFigure(
            new Vector2(0.1f, -0.6f),
            new Vector2(0.7f, -0.6f),
            new Vector2(0.4f, -0.1f),
            new Color(0.0f, 0.0f, 1.0f)
    );*/

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Vertex, Primitive & Color");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
    return 0;
}