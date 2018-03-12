/*
 * rectangle.h
 *
 *  Created on: 2017年10月3日
 *      Author: Crown
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "point.h"
#include "circle.h"

/**
 * Define and typedef a struct Rectangle that contains a Point variable origin that
 * is the top left corner of the rectangle, and two double variables width and height.
 */
typedef struct Rectangle {
    Point *origin;
    double width;
    double height;
} Rectangle;

/**
 * Dynamically allocate and initialize a rectangle.
 *
 * @param p rectangle's origin point
 * @param w rectangle's width
 * @param h rectangle's height
 * @return a pointer to a Rectangle
 */
Rectangle *createRectangle(Point *p, const double w, const double h);

/**
 * Sets the fields of Rectangle to the bounding box that encloses the circle.
 *
 * @param c pointer to an input parameter Circle
 * @return a pointer to the circle's bounding box.
 */
Rectangle *getBoundingBox(Circle *c);

#endif /* RECTANGLE_H_ */
