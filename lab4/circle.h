//
// Created by Artur Gęsiarz on 18/04/2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes{

    class circle : public Shape {

    public:
        circle(int xCenter, int yCenter, int radius);

        bool isIn(int x, int y) const override;

        int x() const;
        int y() const;
        int radius() const;


    private:
        // (x - x_s)^2 + (y - y_s)^2 <= r^2 -> rownanie okregu
        int xCenter;
        int yCenter;
        int r;

    };
}




#endif //CIRCLE_H
