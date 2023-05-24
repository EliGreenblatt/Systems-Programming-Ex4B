#ifndef POINT_
#define POINT_
#include <string>
namespace ariel
{
    class Point
    {
        public:
            Point(double xLoc , double yLoc);
            Point(const Point& otherP);
            static Point moveTowards(Point currPoint , Point destPoint , double distancecToPoint);
            Point();
            double distance(Point otherP) const;
            std::string print() const;
            double getX();
            double getY();
        
        private: 
            double x;
            double y;


    };
}


#endif 