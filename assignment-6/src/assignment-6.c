/*
 ============================================================================
 Name        : assignment-6.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : assignment-6
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

/**
 * Define and typedef a struct Point that contains two double variables x and y.
 */
typedef struct Point {
    double x;
    double y;
} Point;

/**
 * Define and typedef a struct Circle that contains a double variable radius and
 * a Point variable center.
 */
typedef struct Circle {
    double radius;
    Point  center;
} Circle;

/**
 * Define and typedef a struct Rectangle that contains a Point variable origin that
 * is the top left corner of the rectangle, and two double variables width and height.
 */
typedef struct Rectangle {
    Point  origin;
    double width;
    double height;
} Rectangle;

/**
 * Takes pointers to two Point structs, and computes the distance between them.
 * The distance between two points is the square root of the square of the x distances
 * plus the square of the y distances for the two points.
 *
 * @param point1 pointer to one point
 * @param point2 pointer to the other point
 * @return the distance between two points
 */
double distanceofPoints(const Point* point1, const Point* point2) {
    assert((point1 != NULL) && (point2 != NULL));
    return sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
}

/**
 * Takes pointers two Circle structs and returns true if the two Circles intersect
 * and false otherwise.
 *
 * @param c1 pointer to one circle to compute
 * @param c2 pointer to the other circle to compute
 * @return true if the two Circles intersect and false otherwise
 */
bool intersectsCircles(const Circle* c1, const Circle* c2) {
    assert((c1 != NULL) && (c2 != NULL));
    return (c1->radius + c2->radius) > distanceofPoints(&c1->center, &c2->center);
}

/**
 * The function sets the fields of Rectangle to the bounding box that encloses the
 * circle. The function returns a pointer to the Rectangle result parameter.
 *
 * @param circle      pointer to an input parameter Circle
 * @param boundingBox pointer to a Rectangle result parameter boundingBox.
 * @return a pointer to the Rectangle result parameter.
 */
Rectangle* getBoundingBox(const Circle* circle, Rectangle* boundingBox) {
    assert((circle != NULL) && (boundingBox != NULL));

    boundingBox->origin.x = circle->center.x - circle->radius;
    boundingBox->origin.y = circle->center.y + circle->radius;
    boundingBox->width    = circle->radius * 2;
    boundingBox->height   = circle->radius * 2;

    return boundingBox;
}

/**
 * test of function intersectsCircles()
 *
 * @param c1 one of the circles
 * @param c2 one of the circles
 * @param c3 one of the circles
 * @param c4 one of the circles
 */
void testofIntersectsCircles(const Circle* c1, const Circle* c2, const Circle* c3, const Circle* c4) {
    assert((c1 != NULL) && (c2 != NULL) && (c3 != NULL) && (c4 != NULL));

    /**
     * tests the intersectsCircles() function using the cases provided.
     */
    printf("circle at 0,0 radius 10, and circle at 21,0, radius 10: intersect: expected: do not intersect; results: %s.\n",
            intersectsCircles(c1, c2) ? "intersects" : "do not intersect");
    printf("circle at 0,0 radius 10, and circle at 20,0, radius 10: intersect: expected: do not intersect; results: %s.\n",
            intersectsCircles(c1, c3) ? "intersects" : "do not intersect");
    printf("circle at 0,0 radius 10, and circle at 19,0, radius 10: intersect: expected: intersect       ; results: %s.\n",
            intersectsCircles(c1, c4) ? "intersects" : "do not intersect");
}

/**
 * test of function getBoundingBox()
 *
 * @param c1 one of the circles
 * @param c2 one of the circles
 * @param c3 one of the circles
 * @param c4 one of the circles
 */
void testofGetBoundingBox(const Circle* c1, const Circle* c2, const Circle* c3, const Circle* c4) {
    assert((c1 != NULL) && (c2 != NULL) && (c3 != NULL) && (c4 != NULL));

    /**
     * declaring an uninitialized Rectangle boundingBox and calling the getBoundingBox()
     * function for circle1, circle2, circle3, and circle4. Print the origin, width, and
     * height of the boundingBox for each circle.
     */
    Rectangle boundingBox;
    getBoundingBox(c1, &boundingBox);
    printf("circle at  0,0 radius 10 's bounding box: origin->(%.1f, %.1f), width->%.1f, height->%.1f.\n",
            boundingBox.origin.x, boundingBox.origin.y, boundingBox.width, boundingBox.height);

    getBoundingBox(c2, &boundingBox);
    printf("circle at 21,0 radius 10 's bounding box: origin->( %.1f, %.1f), width->%.1f, height->%.1f.\n",
            boundingBox.origin.x, boundingBox.origin.y, boundingBox.width, boundingBox.height);

    getBoundingBox(c3, &boundingBox);
    printf("circle at 20,0 radius 10 's bounding box: origin->( %.1f, %.1f), width->%.1f, height->%.1f.\n",
            boundingBox.origin.x, boundingBox.origin.y, boundingBox.width, boundingBox.height);

    getBoundingBox(c4, &boundingBox);
    printf("circle at 19,0 radius 10 's bounding box: origin->(  %.1f, %.1f), width->%.1f, height->%.1f.\n",
            boundingBox.origin.x, boundingBox.origin.y, boundingBox.width, boundingBox.height);
}

/**
 * Main program for test of assignment-6
 */
int main(void) {
    /**
     * initiate the four circles.
     */
    Circle c1 = { .radius = 10.0, .center = {.x =  0.0, .y = 0.0} };
    Circle c2 = { .radius = 10.0, .center = {.x = 21.0, .y = 0.0} };
    Circle c3 = { .radius = 10.0, .center = {.x = 20.0, .y = 0.0} };
    Circle c4 = { .radius = 10.0, .center = {.x = 19.0, .y = 0.0} };

    /**
     * test of function intersectsCircle()
     */
    printf("This is the test of function intersectsCircles():\n");
    testofIntersectsCircles(&c1, &c2, &c3, &c4);
    /**
     * test of function testofGetBoundingBox()
     */
    printf("\nThis is the test of function getBoundingBox():\n");
    testofGetBoundingBox(&c1, &c2, &c3, &c4);

    return EXIT_SUCCESS;
}
