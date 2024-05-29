#include "Point2D.h"
#include <cmath>
#include <algorithm> // Add this header

Point2D::Point2D(int x, int y) : x(x), y(y) {}

double Point2D::distanceTo(const Point2D& point) const {
    return std::sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}

bool Point2D::equals(const Point2D& point) const {
    return x == point.x && y == point.y;
}

void Point2D::moveWithinBounds(int dx, int dy, int minX, int maxX, int minY, int maxY) {
    x = std::max(minX, std::min(maxX, x + dx));
    y = std::max(minY, std::min(maxY, y + dy));
}
