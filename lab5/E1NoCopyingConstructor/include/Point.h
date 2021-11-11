//
// Created by CQ07 on 2021-11-11.
//

#ifndef E1NOCOPYINGCONSTRUCTOR_POINT_H
#define E1NOCOPYINGCONSTRUCTOR_POINT_H

#include <iostream>

using namespace std;

class Point {
private:
    double *x = new double;
    double *y = new double;
    string name;

public:
    /**
     * Create point in passed place
     * @param x x coordinate of point
     * @param y y coordinate of point
     * @param name name of point
     */
    Point(double x, double y, string name);

    /**
     * Create point in 0, 0
     * @param name name of point
     */
    Point(string name);

    Point(Point &point)
    {
        x = new double;
        *x = *point.x;
        y = new double;
        *y = *point.y;
    }

    /**
     * Update name of point
     * @param name new point name
     */
    void setName(string name);

    /**
     * Get value of x
     * @return x
     */
    double getX();

    /**
     * Update x value
     * @param x new x value
     */
    void setX(double x);

    /**
     * Get value of y
     * @return y
     */
    double getY();

    /**
     * Update y value
     * @param y new y value
     */
    void setY(double y);

    /**
     * Print data about point (x and y)
     */
    void printData() const;

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    Point operator+=(const Point &rhs) const;

    Point operator+=(const double &rhs) const;

    const string &getName() const;

    ~Point()
    {
        delete x;
        delete y;
    }
};


#endif //E1NOCOPYINGCONSTRUCTOR_POINT_H
