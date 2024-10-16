//
// Created by Artur Gęsiarz on 18/04/2024.
//

#include <cmath>
#include "circle.h"

bool Shapes::circle::isIn(int x, int y) const {
    if ( std::pow(x - xCenter, 2) + std::pow(y - yCenter, 2) <= std::pow(r, 2)) {
        return true;
    }
    return false;
}

Shapes::circle::circle(int xCenter, int yCenter, int radius)  :
        xCenter(xCenter),
        yCenter(yCenter),
        r(radius) {

}

int Shapes::circle::x() const {
    return xCenter;
}

int Shapes::circle::y() const {
    return yCenter;
}

int Shapes::circle::radius() const {
    return r;
}
