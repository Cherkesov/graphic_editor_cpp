//
// Created by GoForBroke on 28.02.2016.
//

#ifndef GRAPHIC_EDITOR_CPP_POLYLINE_H
#define GRAPHIC_EDITOR_CPP_POLYLINE_H


#include "AbstractFigure.h"
#include <list>
#include "../Vector2.h"
#include "../Color.h"

class PolyLineFigure : public AbstractFigure {
public:
    virtual void render();

    void addPoint(Vector2 *point);

private:
    std::list<Vector2 *> points;
};


#endif //GRAPHIC_EDITOR_CPP_POLYLINE_H

void PolyLineFigure::render() {
    glLineWidth(1);
    glColor3f(
            this->borderColor->getRed(),
            this->borderColor->getGreen(),
            this->borderColor->getBlue()
    );
    glBegin(GL_LINES);

    for (std::list<Vector2 *>::iterator it = points.begin(); it != points.end(); ++it) {
        glVertex2f(
                (*it)->getX(),
                (*it)->getY()
        );
    }

    glEnd();

}

void PolyLineFigure::addPoint(Vector2 *point) {
    points.push_back(point);
}
