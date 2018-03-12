/*
 ============================================================================
 Name        : assignment-7.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : assignment-7
 ============================================================================
 */

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include <stdlib.h>

// declaration of main test function in test_all.c
extern CU_ErrorCode test_all();

/**
* Main program to invoke test functions
*
* @return the exit status of the unit tests
*/
int main(void) {
    /** test all the functions */
    CU_ErrorCode code = test_all();

    return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}
