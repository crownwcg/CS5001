/*
 * vcache_test.c
 *
 * This file contains a test suite of function for Issn
 *
 * Assignment 9
 * CS 5001, Fall 2017
 * Northeastern University Silicon Valley
 */

#include <stdio.h>
#include <stdlib.h>
#include "issn.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/**
 * Test issn functions
 */
static void test_issn(void) {
    char str[20];

    Issn issns[] = {378595, 1542773, 1078, 18923, 2434561, 2049363, 2348795};
    char *issnStrs[] = {"0378-5955", "1542-7730", "0001-0782", "0018-9235", "2434-561X", "2049-3630", "2348-795X"};

    // check valid Issn
    for (int i = 0; i < 7; i++) {
        CU_ASSERT_STRING_EQUAL(issnToString(issns[i], str), issnStrs[i]);
        CU_ASSERT_EQUAL(parseIssn(issnToString(issns[i], str)), issns[i]);
        CU_ASSERT_EQUAL(parseIssn(issnStrs[i]), issns[i]);
    }

    // parse invalid ISSN
    CU_ASSERT_EQUAL(parseIssn("0378-5956"), NO_ISSN);

    CU_ASSERT_EQUAL(parseIssn("15a2-7731"), NO_ISSN);

    CU_ASSERT_EQUAL(parseIssn("1542--773"), NO_ISSN);

    CU_ASSERT_EQUAL(parseIssn("378-5956" ), NO_ISSN);
}

/**
 * Add suite for issn unit tests
 */
void issn_test(void) {
	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("issn_test", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_issn", test_issn);
}
