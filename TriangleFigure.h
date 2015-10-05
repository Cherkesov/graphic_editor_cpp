//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_TRIANGLEFIGURE_H
#define GRAPHIC_EDITOR_CPP_TRIANGLEFIGURE_H

#include "Figure.h"
#include "Vector2.h"
#include "Color.h"

class TriangleFigure : Figure {
public:
    TriangleFigure() {
        this->setColor(new Color(0.5f, 0.5f, 0.5f));
    }

    TriangleFigure(Vector2 *point1, Vector2 *point2, Vector2 *point3, Color *color) :
            point1(point1),
            point2(point2),
            point3(point3) {
        this->setColor(color);
    }

    TriangleFigure(Vector2 *point1, Vector2 *point2, Vector2 *point3) :
            point1(point1),
            point2(point2),
            point3(point3) {
        this->setColor(new Color(0.5f, 0.5f, 0.5f));
    }

    virtual ~TriangleFigure() {
        delete this->point1;
        delete this->point2;
        delete this->point3;
        delete this->color;
    }

    virtual void render();

private:
    Vector2 *point1;
    Vector2 *point2;
    Vector2 *point3;
};

#endif //GRAPHIC_EDITOR_CPP_TRIANGLEFIGURE_H
