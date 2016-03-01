//
// Created by GoForBroke on 02.03.2016.
//

#ifndef LAUNCHER_LINEFIGURE_H
#define LAUNCHER_LINEFIGURE_H


#include "AbstractFigure.h"
#include "../Vector2.h"

class LineFigure : public AbstractFigure {
public:
    virtual void render();

    Vector2 *getPoint1() const { return point1; }

    void setPoint1(Vector2 *point1) { LineFigure::point1 = point1; }

    Vector2 *getPoint2() const { return point2; }

    void setPoint2(Vector2 *point2) { LineFigure::point2 = point2; }

private:
    Vector2 *point1;
    Vector2 *point2;
};


#endif //LAUNCHER_LINEFIGURE_H

void LineFigure::render() {
    if (NULL == getPoint1() || NULL == getPoint2()) {
        return;
    }

    glLineWidth(1);
    glColor3f(
            this->borderColor->getRed(),
            this->borderColor->getGreen(),
            this->borderColor->getBlue()
    );

    glBegin(GL_LINES);
    {
        glVertex2f(point1->getX(), point1->getY());
        glVertex2f(point2->getX(), point2->getY());
    }
    glEnd();

}