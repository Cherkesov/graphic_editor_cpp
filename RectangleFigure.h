//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_RECTANGLEFIGURE_H
#define GRAPHIC_EDITOR_CPP_RECTANGLEFIGURE_H

#include "Vector2.h"
#include "Figure.h"

class RectangleFigure: Figure {
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

    virtual void render();

private:
    Vector2 *topLeftPoint;
    Vector2 *size;
};


#endif //GRAPHIC_EDITOR_CPP_RECTANGLEFIGURE_H
