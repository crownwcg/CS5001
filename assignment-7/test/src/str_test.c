/*
 * Str_test.c
 *
 *  Created on: 2017年10月10日
 *      Author: Crown
 */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "str.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * test of Str-realted functions()
 */
static void testOfStr(void) {
    /** test of dupstr */
    const char *str = dupStr("Hello world");
    CU_ASSERT_PTR_NOT_NULL_FATAL(str);
    CU_ASSERT_STRING_EQUAL(str, "Hello world");

    /** test of splitString */
    char *spstr = splitString(str, ' ');
    CU_ASSERT_PTR_NOT_NULL_FATAL(spstr);
    CU_ASSERT_STRING_EQUAL(spstr, "Hello");

    /** test of nextSplitString */
    char *spstrNext = nextSplitString(spstr);
    CU_ASSERT_PTR_NOT_NULL_FATAL(spstrNext);
    CU_ASSERT_STRING_EQUAL(spstrNext, "world");

    /** test of nextSplitString */
    size_t size = splitStringSize(spstr);
    CU_ASSERT_EQUAL(size, 2);
}

/**
 * Add suite for Str unit tests
 */
void str_test(void) {
    // add a suite to the registry with no init or cleanup
    CU_pSuite pSuite = CU_add_suite("str_test", NULL, NULL);

    // add the tests to the suite
    CU_add_test(pSuite, "str_test", testOfStr);

}
