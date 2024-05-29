#include "Point2D.h"
#include <cmath>

Point2D::Point2D(int x, int y) : x(x), y(y) {}

double Point2D::distanceTo(const Point2D& point) const {
    return std::sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}

bool Point2D::equals(const Point2D& point) const {
    return x == point.x && y == point.y;
}
