//
// Created by GoForBroke on 02.03.2016.
//

#ifndef LAUNCHER_STRAIGHTLINETOOL_H
#define LAUNCHER_STRAIGHTLINETOOL_H


#include "AbstractTool.h"
#include "../figure/LineFigure.h"

class StraightLineTool : public AbstractTool {
public:
    virtual void mouseHandler(int button, int state, int x, int y);

    virtual void mouseMotionHandler(int x, int y);

    virtual void keyboardHandler(unsigned char key, int x, int y);

    virtual AbstractFigure *getFigure();

private:
    LineFigure *line;
};


#endif //LAUNCHER_STRAIGHTLINETOOL_H

void StraightLineTool::mouseHandler(int button, int state, int x, int y) {
    if (GLUT_LEFT_BUTTON == button) {
        if (GLUT_DOWN == state) {
            line = new LineFigure();
            line->setPoint1(new Vector2(x, y));
        }

        if (GLUT_UP == state) {
            line->setPoint2(new Vector2(x, y));
        }
    }
}

void StraightLineTool::mouseMotionHandler(int x, int y) {
    if (drawingEnabled) {
        line->setPoint2(new Vector2(x, y));
    }
}

void StraightLineTool::keyboardHandler(unsigned char key, int x, int y) {
    //
}

AbstractFigure *StraightLineTool::getFigure() {
    return line;
}