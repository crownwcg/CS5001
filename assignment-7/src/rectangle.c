/*
 ============================================================================
 Name        : assignment-7.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : assignment-7
 ============================================================================
 */

#include "rectangle.h"
#include <stdlib.h>
#include <assert.h>

/**
 * Dynamically allocate and initialize a rectangle.
 *
 * @param p rectangle's origin point
 * @param w rectangle's width
 * @param h rectangle's height
 * @return a pointer to a Rectangle
 */
Rectangle *createRectangle(Point *p, const double w, const double h) {
    assert(p != NULL);
    Rectangle *rec = malloc(sizeof(Rectangle *));
    rec->origin = p;
    rec->width  = w;
    rec->height = h;

    return rec;
}

/**
 * Sets the fields of Rectangle to the bounding box that encloses the circle.
 *
 * @param c pointer to an input parameter Circle
 * @return a pointer to the circle's bounding box.
 */
Rectangle *getBoundingBox(Circle *c) {
    assert(c != NULL);
    Rectangle *boundingBox = malloc(sizeof(Rectangle *));
    Point *p = createPoint(c->center->x - c->radius, c->center->y + c->radius);
    boundingBox = createRectangle(p, c->radius * 2, c->radius * 2);

    return boundingBox;
}


