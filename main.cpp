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

#include "figure/RectangleFigure.h"

#include "tool/AbstractTool.h"
#include "tool/PencilTool.h"
#include "tool/StraightLineTool.h"

using namespace std;


list<AbstractFigure *> figures;


AbstractTool *currentTool = new StraightLineTool();


Vector2 *mousePos = new Vector2();


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

    list<AbstractFigure *>::iterator it;
    for (it = figures.begin(); it != figures.end(); ++it) {
        (*it)->render();
    }

    if (NULL != currentTool->getFigure())
        currentTool->getFigure()->render();

    ostringstream string1;
    string1 << mousePos->getX() << ":" << mousePos->getY();
    RenderString(10, WINDOW_HEIGHT - 10, GLUT_BITMAP_TIMES_ROMAN_24, string1.str().c_str());

    glFlush(); // Render now
}

// Keyboard method to allow ESC key to quit
void keyboardHandler(unsigned char key, int x, int y) {
    if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    currentTool->keyboardHandler(key, x, y);
}

void mouseHandler(int button, int state, int x, int y) {
    currentTool->setDrawingEnabled(
            GLUT_LEFT_BUTTON == button
            && GLUT_DOWN == state
    );

    currentTool->mouseHandler(button, state, x, y);

    if (NULL != currentTool && GLUT_LEFT_BUTTON == button && GLUT_UP == state) {
        figures.push_back(currentTool->getFigure());
    }
}

void mouseMotionHandler(int x, int y) {
    mousePos->setX(x);
    mousePos->setY(y);

    currentTool->mouseMotionHandler(x, y);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    glutInitWindowPosition(150, 150);
    glutCreateWindow("Vertex, Primitive & Color");

    glutDisplayFunc(displayFunc);
    glutIdleFunc(displayFunc); // Чтоб перерисовывать картинку по время простоя

    glutKeyboardFunc(keyboardHandler);

    glutMouseFunc(mouseHandler);

    glutMotionFunc(mouseMotionHandler);
    glutPassiveMotionFunc(mouseMotionHandler);

    initGL();
    glutMainLoop();
    return 0;
}