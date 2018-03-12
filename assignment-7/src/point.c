/*
 ============================================================================
 Name        : assignment-7.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : assignment-7
 ============================================================================
 */

#include "point.h"
#include <stdlib.h>

/**
 * Dynamically allocate and initialize a point.
 *
 * @param x horizontal coordinate
 * @param y vertical coordinate
 * @return a pointer to a Point
 */
Point *createPoint(const double x, const double y) {
    Point *p = malloc(sizeof(Point *));
    p->x = x;
    p->y = y;

    return p;
}


