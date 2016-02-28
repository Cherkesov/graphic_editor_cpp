//
// Created by GoForBroke on 28.02.2016.
//

#ifndef GRAPHIC_EDITOR_CPP_CIRCLEFIGURE_H
#define GRAPHIC_EDITOR_CPP_CIRCLEFIGURE_H

#include "Figure.h"
#include "Vector2.h"
#include <math.h>

#define PI 3.1415926535897932384626433832795

class CircleFigure : public Figure {
public:
    CircleFigure(Vector2 *point, float radius, Color *color) {
        this->point = point;
        this->radius = radius;
        this->setColor(color);
    }

    void render() {
        /*glBegin(GL_POINT);
        {
            glColor3f(
                    this->getColor()->getRed(),
                    this->getColor()->getGreen(),
                    this->getColor()->getBlue()
            );
            glVertex2f(this->point->getX(), this->point->getY());
        }
        glEnd();*/

        glBegin(GL_POLYGON);
        glColor3f(
                this->getColor()->getRed(),
                this->getColor()->getGreen(),
                this->getColor()->getBlue()
        );

        //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
        //Note that anything above 24 will have little affect on the circles appearance
        //Play with the numbers till you find the result you are looking for
        //Value 1.5 - Draws Triangle
        //Value 2 - Draws Square
        //Value 3 - Draws Hexagon
        //Value 4 - Draws Octagon
        //Value 5 - Draws Decagon
        //Notice the correlation between the value and the number of sides
        //The number of sides is always twice the value given this range
        for (double i = 0; i < 2 * PI; i += PI / 6) //<-- Change this Value
            glVertex2f(
                    this->point->getX() + cos(i) * this->radius,
                    this->point->getY() + sin(i) * radius
            );
        glEnd();
    }

private:
    Vector2 *point;
    float radius;
};


#endif //GRAPHIC_EDITOR_CPP_CIRCLEFIGURE_H
