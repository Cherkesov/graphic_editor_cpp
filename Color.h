//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_COLOR_H
#define GRAPHIC_EDITOR_CPP_COLOR_H

#include <GL/gl.h>

class Color {
public:
    Color(GLfloat red, GLfloat green, GLfloat blue) :
            red(red),
            green(green),
            blue(blue) { }

private:
    GLfloat red;
    GLfloat green;
    GLfloat blue;

public:
    GLfloat getRed() const {
        return red;
    }

    void setRed(GLfloat red) {
        Color::red = red;
    }

    GLfloat getGreen() const {
        return green;
    }

    void setGreen(GLfloat green) {
        Color::green = green;
    }

    GLfloat getBlue() const {
        return blue;
    }

    void setBlue(GLfloat blue) {
        Color::blue = blue;
    }
};


#endif //GRAPHIC_EDITOR_CPP_COLOR_H
