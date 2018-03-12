/*
 * test_all.c
 *
 *  Created on: 2017年10月10日
 *      Author: Crown
 */

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

// module test functions
extern void rectangle_test(void);
extern void str_test(void);

/**
 * Unit test driver
 *
 * @return test error code
 */
CU_ErrorCode test_all(void) {
    // initialize the CUnit test registry – only once per application
    CU_initialize_registry();

    // call functions to register test suites
    rectangle_test();            // register rectangle test suite
    str_test();                  // register string test suite

    // run all suites using the basic interface that echoes to the console in this example
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // display information on failures that occurred
    CU_basic_show_failures(CU_get_failure_list());

    // Clean up registry and return status
    CU_cleanup_registry();
    return CU_get_error();
}

