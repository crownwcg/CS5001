/*
 * test_all.c
 *
 * This file sets up and runs unit tests.
 *
 */
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

// module test functions
extern void vcache_test(void);

/**
 * Unit test driver
 *
 * @return test error code
 */
CU_ErrorCode test_all(void) {
	// initialize the CUnit test registry – only once per application
	CU_initialize_registry();

    // call functions to register test suites
    vcache_test();	        // register vcache test suite

	// run all suites using the basic interface that echoes to the console in this example
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	// display information on failures that occurred
	CU_basic_show_failures(CU_get_failure_list());

	// Clean up registry and return status
	CU_cleanup_registry();
	return CU_get_error();
}



