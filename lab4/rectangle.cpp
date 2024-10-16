//
// Created by Artur Gęsiarz on 18/04/2024.
//

#include "rectangle.h"

bool Shapes::rectangle::isIn(int x, int y) const {

    if (xFrom <= x && x <= xEnd)
        if (yFrom <= y && y <= yEnd)
            return true;

    return false;
}

Shapes::rectangle::rectangle(int xFrom, int yFrom, int xTo, int yTo)  :
        xFrom(xFrom),
        yFrom(yFrom),
        xEnd(xTo),
        yEnd(yTo)  {
}

int Shapes::rectangle::x() const {
    return xFrom;
}

int Shapes::rectangle::xTo() const {
    return xEnd;
}

int Shapes::rectangle::y() const {
    return yFrom;
}

int Shapes::rectangle::yTo() const {
    return yEnd;
}
