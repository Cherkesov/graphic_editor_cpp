//
// Created by GoForBroke on 28.02.2016.
//

#ifndef GRAPHIC_EDITOR_CPP_ABSTRACTTOOL_H
#define GRAPHIC_EDITOR_CPP_ABSTRACTTOOL_H

#include <list>

class AbstractTool {
public:
    AbstractTool() :
            drawingEnabled(false) { }

    // Check mouse buttons for press/release
    virtual void mouseHandler(int button, int state, int x, int y) = 0;

    // Handle mouse movement
    virtual void mouseMotionHandler(int x, int y) = 0;

    // Handle keyboard button press/release
    virtual void keyboardHandler(unsigned char key, int x, int y) = 0;

    virtual AbstractFigure *getFigure() = 0;


    bool isDrawingEnabled() const { return drawingEnabled; }

    void setDrawingEnabled(bool drawingEnabled) { AbstractTool::drawingEnabled = drawingEnabled; }

protected:
    bool drawingEnabled;
};


#endif //GRAPHIC_EDITOR_CPP_ABSTRACTTOOL_H
