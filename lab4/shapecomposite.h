//
// Created by Artur Gęsiarz on 18/04/2024.
//

#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H


#include <memory>
#include "shape.h"

namespace Shapes {

    enum class ShapeOperation {
        INTERSECTION,
        SUM,
        DIFFERENCE
    };

    class shapecomposite : public Shape {

    public:
        shapecomposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation);
        bool isIn(int x, int y) const override;

    private:
        std::shared_ptr<Shape> shape1;
        std::shared_ptr<Shape> shape2;
        ShapeOperation operation;
    };
}


#endif //SHAPECOMPOSITE_H
