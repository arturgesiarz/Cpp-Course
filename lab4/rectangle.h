//
// Created by Artur Gęsiarz on 18/04/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes{

    class rectangle : public Shape {

    public:
        rectangle(int xFrom, int yFrom, int xTo, int yTo);
        bool isIn(int x, int y) const override;

        int x() const;
        int xTo() const;
        int y() const;
        int yTo() const;

    private:
        int xFrom;
        int yFrom;
        int xEnd;
        int yEnd;
    };
}

#endif //RECTANGLE_H
