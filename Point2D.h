#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
public:
    int x, y;

    Point2D(int x = 0, int y = 0);

    double distanceTo(const Point2D& point) const;

    bool equals(const Point2D& point) const;

    void moveWithinBounds(int dx, int dy, int minX, int maxX, int minY, int maxY);
};

#endif // POINT2D_H
