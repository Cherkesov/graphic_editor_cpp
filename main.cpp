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
#include <list>

#include "TriangleFigure.h"
#include "RectangleFigure.h"
#include "CircleFigure.h"

using namespace std;


list<Figure*> figures;

Vector2 *mousePos = new Vector2();

bool leftBtnPressed = false;

void RenderString(float x, float y, void *font, const char *str) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(x, y);
    glutBitmapString(font, (const unsigned char *) str);
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    list<Figure*>::iterator it;
    for (it = figures.begin(); it != figures.end(); ++it) {
        (*it)->render();
    }

    ostringstream string1;
    string1 << mousePos->getX() << ":" << mousePos->getY();
    RenderString(10, 590, GLUT_BITMAP_TIMES_ROMAN_24, string1.str().c_str());

    glFlush(); // Render now
}

// Keyboard method to allow ESC key to quit
void keyboardFunc(unsigned char key, int x, int y) {
    if (key == 27) {
        glutLeaveMainLoop();
    }
}

void mouseHandler(int button, int state, int x, int y) {
    //GLUT_LEFT_BUTTON
    //GLUT_RIGHT_BUTTON
    //GLUT_MIDDLE_BUTTON

    //GLUT_DOWN
    //GLUT_UP

    if (GLUT_LEFT_BUTTON == button) {
        leftBtnPressed = (GLUT_DOWN == state);
    }
}

void mouseMotionHandler(int x, int y) {
    mousePos->setX(x);
    mousePos->setY(y);

    if (leftBtnPressed) {
        figures.push_back(new CircleFigure(
                new Vector2(x, y),
                1,
                new Color(1.0f, 1.0f, 1.0f)
        ));
    }
}

int main(int argc, char **argv) {

    /*figures.push_back(new TriangleFigure(
            new Vector2(600, 400),
            new Vector2(700, 500),
            new Vector2(500, 500),
            new Color(0.0f, 0.0f, 1.0f)
    ));
    figures.push_back(new TriangleFigure(
            new Vector2(100, 100),
            new Vector2(200, 100),
            new Vector2(100, 200),
            new Color(0.0f, 0.0f, 1.0f)
    ));*/
    /*figures.push_back(new RectangleFigure(
            new Vector2(400, 400),
            new Vector2(50, 50),
            new Color(0.0f, 1.0f, 1.0f)
    ));
    figures.push_back(new CircleFigure(
            new Vector2(100, 100),
            1,
            new Color(0.0f, 1.0f, 1.0f)
    ));
    figures.push_back(new CircleFigure(
            new Vector2(200, 200),
            1,
            new Color(0.0f, 1.0f, 1.0f)
    ));*/



    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    glutInitWindowPosition(150, 150);
    glutCreateWindow("Vertex, Primitive & Color");

    glutDisplayFunc(displayFunc);
    glutIdleFunc(displayFunc); // Чтоб перерисовывать картинку по время простоя

    glutKeyboardFunc(keyboardFunc);

    glutMouseFunc(mouseHandler);

    glutMotionFunc(mouseMotionHandler);
    glutPassiveMotionFunc(mouseMotionHandler);

    initGL();
    glutMainLoop();
    return 0;
}