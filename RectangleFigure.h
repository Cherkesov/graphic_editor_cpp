//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_RECTANGLEFIGURE_H
#define GRAPHIC_EDITOR_CPP_RECTANGLEFIGURE_H

#include "Vector2.h"
#include "Figure.h"

class RectangleFigure : public Figure {
public:
    RectangleFigure() {
        this->topLeftPoint = new Vector2(0, 0);
        this->size = new Vector2(0.25f, 0.25f);
        this->color = new Color(0.5f, 0.5f, 0.5f);
    }

    RectangleFigure(Vector2 *topLeftPoint, Vector2 *size, Color *color) :
            topLeftPoint(topLeftPoint),
            size(size) {
        this->setColor(color);
    }

    virtual ~RectangleFigure() {
        delete this->topLeftPoint;
        delete this->size;
        delete this->color;
    }

    void render() {
        glBegin(GL_QUADS);
        {
            glColor3f(
                    this->getColor()->getRed(),
                    this->getColor()->getGreen(),
                    this->getColor()->getBlue()
            );
            glVertex2f(this->topLeftPoint->getX(), this->topLeftPoint->getY());
            glVertex2f(this->topLeftPoint->getX() + this->size->getX(), this->topLeftPoint->getY());
            glVertex2f(this->topLeftPoint->getX() + this->size->getX(),
                       this->topLeftPoint->getY() + this->size->getY());
            glVertex2f(this->topLeftPoint->getX(), this->topLeftPoint->getY() + this->size->getY());
        }
        glEnd();
    }

private:
    Vector2 *topLeftPoint;
    Vector2 *size;
};


#endif //GRAPHIC_EDITOR_CPP_RECTANGLEFIGURE_H
