//
// Created by GoForBroke on 28.02.2016.
//

#ifndef GRAPHIC_EDITOR_CPP_PENCILTOOL_H
#define GRAPHIC_EDITOR_CPP_PENCILTOOL_H

#include "AbstractTool.h"
#include "../figure/PolyLineFigure.h"

class PencilTool : public AbstractTool {

public:
    PencilTool(const std::list<AbstractFigure *> &canvasContent) :
            AbstractTool(canvasContent) {
        line = new PolyLineFigure();
    }

    virtual void mouseHandler(int button, int state, int x, int y);

    virtual void mouseMotionHandler(int x, int y);

    virtual void keyboardHandler(unsigned char key, int x, int y);

    virtual AbstractFigure* getFigure();

private:
    PolyLineFigure *line;
};


#endif //GRAPHIC_EDITOR_CPP_PENCILTOOL_H

void PencilTool::mouseHandler(int button, int state, int x, int y) {
    if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state)
        line = new PolyLineFigure();
}

void PencilTool::mouseMotionHandler(int x, int y) {
    if (drawingEnabled)
        line->addPoint(new Vector2(x, y));
}

void PencilTool::keyboardHandler(unsigned char key, int x, int y) {

}

AbstractFigure* PencilTool::getFigure() {
    return line;
}
