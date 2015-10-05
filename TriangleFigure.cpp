//
// Created by Sergey on 05.10.2015.
//

#include <GL/gl.h>
#include "TriangleFigure.h"

void TriangleFigure::render() {
    glBegin(GL_TRIANGLES);
    {
        glColor3f(
                this->getColor()->getRed(),
                this->getColor()->getGreen(),
                this->getColor()->getBlue()
        );
        glVertex2f(this->point1->getX(), this->point1->getY());
        glVertex2f(this->point2->getX(), this->point2->getY());
        glVertex2f(this->point3->getX(), this->point3->getY());
    }
    glEnd();
}
