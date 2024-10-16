//
// Created by Artur Gęsiarz on 18/04/2024.
//

#include "shapecomposite.h"

#include <utility>



bool Shapes::shapecomposite::isIn(int x, int y) const {
    switch (operation) {
        case ShapeOperation::INTERSECTION:
            return (shape1->isIn(x, y) && shape2->isIn(x, y));
        case ShapeOperation::SUM:
            return (shape1->isIn(x, y) || shape2->isIn(x, y));
        case ShapeOperation::DIFFERENCE:
            return (shape1->isIn(x, y) && !shape2->isIn(x, y));
        default:
            return false;
    }
}

Shapes::shapecomposite::shapecomposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                                       Shapes::ShapeOperation operation)  :
        shape1(std::move(shape1)),
        shape2(std::move(shape2)),
        operation(operation) {

}
