#define GLUT_DISABLE_ATEXIT_HACK

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;

#ifdef _WIN32

#include <windows.h>

#endif

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <sstream>

#include "TriangleFigure.h"
#include "RectangleFigure.h"

using namespace std;

Vector2 *mousePos = new Vector2();

TriangleFigure *triangleFigure1 = new TriangleFigure(
        new Vector2(0.1f, -0.6f),
        new Vector2(0.7f, -0.6f),
        new Vector2(0.4f, -0.1f),
        new Color(0.0f, 0.0f, 1.0f)
);

TriangleFigure *triangleFigure2 = new TriangleFigure(
        new Vector2(100, 100),
        new Vector2(200, 100),
        new Vector2(100, 200),
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

void RenderString(float x, float y, void *font, const char *string) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(x, y);
    glutBitmapString(font, (const unsigned char *) string);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    rectangleFigure1->render();
    triangleFigure1->render();
    triangleFigure2->render();

    ostringstream string1;
    string1 << mousePos->getX() << ":" << mousePos->getY();
    RenderString(10, 590, GLUT_BITMAP_TIMES_ROMAN_24, string1.str().c_str());

    glFlush();  // Render now
}

// Keyboard method to allow ESC key to quit
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        glutLeaveMainLoop();
    }
}

void mouse(int button, int state, int x, int y) {
    //GLUT_LEFT_BUTTON
    //GLUT_RIGHT_BUTTON
    //GLUT_MIDDLE_BUTTON

    //GLUT_DOWN
    //GLUT_UP
}

void mouseMotion(int x, int y) {
    mousePos->setX(x);
    mousePos->setY(y);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    glutInitWindowPosition(150, 150);
    glutCreateWindow("Vertex, Primitive & Color");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);

    glutMouseFunc(mouse);

    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mouseMotion);

    initGL();
    glutMainLoop();
    return 0;
}