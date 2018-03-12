/*
 ============================================================================
 Name        : assignment-7.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : assignment-7
 ============================================================================
 */

#include "circle.h"
#include <stdlib.h>
#include <assert.h>

/**
 * Dynamically allocate and initialize a circle.
 *
 * @param p circle's center point
 * @param r circle's radius
 * @return a pointer to a Circle
 */
Circle *createCircle(Point *p, const double r) {
    assert(p != NULL);
    Circle *c = malloc(sizeof(Circle *));
    c->center = p;
    c->radius = r;

    return c;
}


