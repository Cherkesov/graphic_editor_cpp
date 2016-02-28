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
#include "figure/CircleFigure.h"
#include "tool/AbstractTool.h"
#include "tool/PencilTool.h"

using namespace std;


list<AbstractFigure *> figures;


AbstractTool *currentTool = new PencilTool(figures);


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
    currentTool->getFigure()->render();

    ostringstream string1;
    string1 << mousePos->getX() << ":" << mousePos->getY();
    RenderString(10, 590, GLUT_BITMAP_TIMES_ROMAN_24, string1.str().c_str());

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
    //GLUT_LEFT_BUTTON
    //GLUT_RIGHT_BUTTON
    //GLUT_MIDDLE_BUTTON

    //GLUT_DOWN
    //GLUT_UP

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

    /*if (leftBtnPressed) {
        figures.push_back(new CircleFigure(
                new Vector2(x, y),
                1,
                new Color(1.0f, 1.0f, 1.0f)
        ));
    }*/
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

    glutKeyboardFunc(keyboardHandler);

    glutMouseFunc(mouseHandler);

    glutMotionFunc(mouseMotionHandler);
    glutPassiveMotionFunc(mouseMotionHandler);

    initGL();
    glutMainLoop();
    return 0;
}