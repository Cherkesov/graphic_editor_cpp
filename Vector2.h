//
// Created by Sergey on 05.10.2015.
//

#ifndef GRAPHIC_EDITOR_CPP_POINT_H
#define GRAPHIC_EDITOR_CPP_POINT_H


class Vector2 {
private:
    float x;
    float y;

public:
    Vector2() { }

    Vector2(float _x, float _y) {
        this->x = _x;
        this->y = _y;
    }

    float getX() const {
        return x;
    }

    void setX(float x) {
        Vector2::x = x;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Vector2::y = y;
    }
};


#endif //GRAPHIC_EDITOR_CPP_POINT_H
