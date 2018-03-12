/*
 * vcache_test.c
 *
 * This file contains a test suite of function for Vcache
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#include <stdio.h>
#include <stdlib.h>
#include "vcache.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/**
 * Test Vcache functions
 */
static void test_vcache(void) {
	const char *str[] = {"Hello", "World", "Happy","C language", "Cache"};

	/** verify function createVcache */
	Vcache *vc = createVcache();
	CU_ASSERT_PTR_NOT_NULL_FATAL(vc);

	for (int i = 0; i < 5; i++) {
	    CU_ASSERT_FALSE(containsVcacheItem(vc, (void *)str[i]));

	    /** verify function addVcacheItem */
	    CU_ASSERT_TRUE(addVcacheItem(vc, (void *)str[i]));

	    /** verify function containsVcacheItem */
	    CU_ASSERT_TRUE(containsVcacheItem(vc, (void *)str[i]));

	    /** verify function getVcacheItemAt */
	    CU_ASSERT_PTR_NOT_NULL(getVcacheItemAt(vc, i));
	    CU_ASSERT_PTR_EQUAL(getVcacheItemAt(vc, i), (void *)str[i]);

	    /** verify size of cache */
	    CU_ASSERT_EQUAL(getVcacheSize(vc), i+1);
	}

    for (int i = 0; i < 5; i++) {
        CU_ASSERT_TRUE(containsVcacheItem(vc, (void *)str[i]));

        /** verify function addVcacheItem with duplicate items */
        CU_ASSERT_FALSE(addVcacheItem(vc, (void *)str[i]));

        /** verify size of cache */
        CU_ASSERT_EQUAL(getVcacheSize(vc), 5);
    }

    /** verify function addVcacheItem with NULL item */
    bool b = addVcacheItem(vc, NULL);
    CU_ASSERT_FALSE(b);

    /** verify invalid index */
    void *p = getVcacheItemAt(vc, 5);
    CU_ASSERT_PTR_NULL(p);

}

/**
 * Add suite for Vcache unit tests
 */
void vcache_test(void) {
	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("vcache_test", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_vcache", test_vcache);
}
