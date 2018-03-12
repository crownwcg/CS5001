/*
 * circle.h
 *
 *  Created on: 2017年10月3日
 *      Author: Crown
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "point.h"

/**
 * Define and typedef a struct Circle that contains a double variable radius and
 * a Point variable center.
 */
typedef struct Circle {
    double radius;
    Point *center;
} Circle;

/**
 * Dynamically allocate and initialize a circle.
 *
 * @param p circle's center point
 * @param r circle's radius
 * @return a pointer to a Circle
 */
Circle *createCircle(Point *p, const double r);

#endif /* CIRCLE_H_ */
