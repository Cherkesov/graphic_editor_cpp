//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_FIGURE_H
#define GRAPHIC_EDITOR_CPP_FIGURE_H


#include "Color.h"

class Figure {
protected:
    Color *color;
public:
    virtual void render() = 0;

    Color *getColor() const {
        return color;
    }

    void setColor(Color *color) {
        Figure::color = color;
    }
};


#endif //GRAPHIC_EDITOR_CPP_FIGURE_H
