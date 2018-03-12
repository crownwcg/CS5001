/*
 * test.c
 *
 *  Created on: 2017年10月4日
 *      Author: Crown
 */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * test of Rectangle-related functions()
 */
static void testOfRectangle() {
    /**
     * initiate the points, circles testing the function createPoint and createCircle.
     */
    Point  *p1 = createPoint( 0, 0);
    CU_ASSERT_PTR_NOT_NULL_FATAL(p1);
    CU_ASSERT_EQUAL(p1->x, 0);
    CU_ASSERT_EQUAL(p1->y, 0);

    Point  *p2 = createPoint(21, 0);
    CU_ASSERT_PTR_NOT_NULL_FATAL(p2);
    CU_ASSERT_EQUAL(p2->x, 21);
    CU_ASSERT_EQUAL(p2->y, 0);

    Point  *p3 = createPoint(20, 0);
    CU_ASSERT_PTR_NOT_NULL_FATAL(p3);
    CU_ASSERT_EQUAL(p3->x, 20);
    CU_ASSERT_EQUAL(p3->y, 0);

    Point  *p4 = createPoint(19, 0);
    CU_ASSERT_PTR_NOT_NULL_FATAL(p4);
    CU_ASSERT_EQUAL(p4->x, 19);
    CU_ASSERT_EQUAL(p4->y, 0);

    Circle *c1 = createCircle(p1, 10);
    CU_ASSERT_PTR_NOT_NULL_FATAL(c1);
    CU_ASSERT_EQUAL(c1->radius, 10);
    CU_ASSERT_PTR_EQUAL(c1->center, p1);

    Circle *c2 = createCircle(p2, 10);
    CU_ASSERT_PTR_NOT_NULL_FATAL(c2);
    CU_ASSERT_EQUAL(c2->radius, 10);
    CU_ASSERT_PTR_EQUAL(c2->center, p2);

    Circle *c3 = createCircle(p3, 10);
    CU_ASSERT_PTR_NOT_NULL_FATAL(c3);
    CU_ASSERT_EQUAL(c3->radius, 10);
    CU_ASSERT_PTR_EQUAL(c3->center, p3);

    Circle *c4 = createCircle(p4, 10);
    CU_ASSERT_PTR_NOT_NULL_FATAL(c4);
    CU_ASSERT_EQUAL(c4->radius, 10);
    CU_ASSERT_PTR_EQUAL(c4->center, p4);

    /**
     * declaring an uninitialized Rectangle boundingBox and calling the getBoundingBox()
     * function for circle1, circle2, circle3, and circle4. Print the origin, width, and
     * height of the boundingBox for each circle.
     */
    Rectangle *boundingBox1 = getBoundingBox(c1);
    CU_ASSERT_PTR_NOT_NULL_FATAL(boundingBox1);
    CU_ASSERT_EQUAL(boundingBox1->origin->x, -10);
    CU_ASSERT_EQUAL(boundingBox1->origin->y, 10);
    CU_ASSERT_EQUAL(boundingBox1->width, 20);
    CU_ASSERT_EQUAL(boundingBox1->height, 20);

    Rectangle *boundingBox2 = getBoundingBox(c2);
    CU_ASSERT_PTR_NOT_NULL_FATAL(boundingBox2);
    CU_ASSERT_EQUAL(boundingBox2->origin->x, 11);
    CU_ASSERT_EQUAL(boundingBox2->origin->y, 10);
    CU_ASSERT_EQUAL(boundingBox2->width, 20);
    CU_ASSERT_EQUAL(boundingBox2->height, 20);

    Rectangle *boundingBox3 = getBoundingBox(c3);
    CU_ASSERT_PTR_NOT_NULL_FATAL(boundingBox3);
    CU_ASSERT_EQUAL(boundingBox3->origin->x, 10);
    CU_ASSERT_EQUAL(boundingBox3->origin->y, 10);
    CU_ASSERT_EQUAL(boundingBox3->width, 20);
    CU_ASSERT_EQUAL(boundingBox3->height, 20);

    Rectangle *boundingBox4 = getBoundingBox(c4);
    CU_ASSERT_PTR_NOT_NULL_FATAL(boundingBox4);
    CU_ASSERT_EQUAL(boundingBox4->origin->x, 9);
    CU_ASSERT_EQUAL(boundingBox4->origin->y, 10);
    CU_ASSERT_EQUAL(boundingBox4->width, 20);
    CU_ASSERT_EQUAL(boundingBox4->height, 20);
}

/**
 * Add suite for rectangle unit tests
 */
void rectangle_test(void) {
    // add a suite to the registry with no init or cleanup
    CU_pSuite pSuite = CU_add_suite("rectangle_test", NULL, NULL);

    // add the tests to the suite
    CU_add_test(pSuite, "rectangle_test", testOfRectangle);

}
