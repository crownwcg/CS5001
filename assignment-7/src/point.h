/*
 * point.h
 *
 *  Created on: 2017年10月3日
 *      Author: Crown
 */

#ifndef POINT_H_
#define POINT_H_

/**
 * Define and typedef a struct Point that contains two double variables x and y.
 */
typedef struct Point {
    double x;
    double y;
} Point;

/**
 * Dynamically allocate and initialize a point.
 *
 * @param x horizontal coordinate
 * @param y vertical coordinate
 * @return a pointer to a Point
 */
Point*  createPoint(const double x, const double y);

#endif /* ASSIGNMENT_7_H_ */
