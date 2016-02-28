//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_FIGURE_H
#define GRAPHIC_EDITOR_CPP_FIGURE_H


#include "../Color.h"

class AbstractFigure {
public:
    AbstractFigure() {
        borderColor = new Color(0.5f, 0.5f, 0.5f);
        fillColor = new Color(0.5f, 0.5f, 0.5f);
    }

    virtual void render() = 0;

    Color *getFillColor() const {
        return fillColor;
    }

    void setFillColor(Color *color) {
        this->fillColor = color;
    }

    Color *getBorderColor() const {
        return borderColor;
    }

    void setBorderColor(Color *borderColor) {
        this->borderColor = borderColor;
    }

protected:
    Color *fillColor;
    Color *borderColor;
};


#endif //GRAPHIC_EDITOR_CPP_FIGURE_H
