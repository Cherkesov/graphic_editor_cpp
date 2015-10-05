//
// Created by Sergey on 05.10.2015.
//

#include <GL/gl.h>
#include "RectangleFigure.h"

void RectangleFigure::render() {
    glBegin(GL_QUADS);
    {
        glColor3f(
                this->getColor()->getRed(),
                this->getColor()->getGreen(),
                this->getColor()->getBlue()
        );
        glVertex2f(this->topLeftPoint->getX(), this->topLeftPoint->getY());
        glVertex2f(this->topLeftPoint->getX() + this->size->getX(), this->topLeftPoint->getY());
        glVertex2f(this->topLeftPoint->getX() + this->size->getX(), this->topLeftPoint->getY() + this->size->getY());
        glVertex2f(this->topLeftPoint->getX(), this->topLeftPoint->getY() + this->size->getY());
    }
    glEnd();
}
