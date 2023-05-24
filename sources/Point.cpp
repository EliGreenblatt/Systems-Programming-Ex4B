#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
using namespace ariel;
using namespace std;

Point::Point()
{

}

Point::Point(const Point& otherP)
{
    x = otherP.x;
    y = otherP.y;
}

Point::Point(double xLoc, double yLoc)
{
    x = xLoc;
    y = yLoc;
}

double Point::distance(Point otherP) const
{
    double diffX = otherP.getX() - x;
    double diffY = otherP.getY() - y;

    return std::sqrt((diffX * diffX) + (diffY * diffY));
}

Point Point::moveTowards(Point currPoint, Point destPoint, double distanceToPoint)
{
    if (distanceToPoint <= 0)
    {
        throw std::invalid_argument("Distance can't be zero\n");
    }

    double pointsDistance = currPoint.distance(destPoint);

    if (pointsDistance <= distanceToPoint)
    {
        return destPoint;
    }
    else
    {
        double diffX = destPoint.x - currPoint.x;
        double diffY = destPoint.y - currPoint.y;
        double ratio = distanceToPoint / pointsDistance;
        double newX = currPoint.getX() + diffX * ratio;
        double newY = currPoint.getY() + diffY * ratio;
        return Point(newX,newY);
    }
}

std::string Point::print() const
{
    std::ostringstream oss;
    oss << "(" << x << "," << y << ")";
    return oss.str();
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}