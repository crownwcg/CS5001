/*
 * main.c
 *
 * Defines main function
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#include <stdio.h>
#include <stdlib.h>
#include "journal.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/**
 * Test Issn functions.
 */
static void test_issn(void) {
    char str[20];  // char array converting Issn to string
    char *s;   // conversion result pointer

    // convert ISSN to string
    Issn issn0 = 12345678;
    s = issnToString(issn0, str);
    CU_ASSERT_STRING_EQUAL(s, "1234-5678");

    // parse string to Issn
    Issn issn_0 = parseIssn(s);
    CU_ASSERT_EQUAL(issn0, issn_0);

    // convert  ISSN with implied leading 0s to string
    Issn issn1 = 345678;
    s = issnToString(issn1, str);
    CU_ASSERT_STRING_EQUAL(s, "0034-5678");

    // parse string to Issn
    Issn issn_1 = parseIssn(s);
    CU_ASSERT_EQUAL(issn1, issn_1);

    // parse invalid ISSN
    Issn issn_2 = parseIssn("012a-5468");
    CU_ASSERT_EQUAL(issn_2, ISSN_UNKNOWN);
    // parse invalid ISSN

    Issn issn_3 = parseIssn("");
    CU_ASSERT_EQUAL(issn_3, ISSN_UNKNOWN);
}

/**
 * Test Publisher functions for local allocation.
 */
static void test_publisher_local(void) {
    const char* pubNames[5] = {
    "National Geographic Society", "Time", "Science Service", "Sunset", "Life"};

    // test local local publisher
    for (int i = 0; i < 5; i++) {
        Publisher p1, p2;

        // create local instance of publisher
        Publisher *pub1 = createPublisher(pubNames[i], &p1);
        CU_ASSERT_PTR_NOT_NULL_FATAL(pub1);
        CU_ASSERT_PTR_EQUAL(pub1, &p1);
        CU_ASSERT_STRING_EQUAL(pub1->name, pubNames[i]);

        // create second instance of publisher
        Publisher *pub2 = createPublisher(pubNames[i], &p2);
        CU_ASSERT_PTR_NOT_NULL_FATAL(pub2);
        CU_ASSERT_PTR_EQUAL(pub2, &p2);
        CU_ASSERT_STRING_EQUAL(pub2->name, pubNames[i]);

        // verify they are different
        CU_ASSERT_PTR_NOT_EQUAL(pub1, pub2);
    }
}

/**
 * Test Publisher functions for dynamic allocation.
 */
static void test_publisher_dynamic(void) {
    const char* pubNames[5] = {
    "National Geographic Society", "Time", "Science Service", "Sunset", "Life"};

    for (int i = 0; i < 5; i++) {
        // create instance of publisher
        Publisher *pub1 = createPublisher(pubNames[i], NULL);
        CU_ASSERT_PTR_NOT_NULL_FATAL(pub1);
        CU_ASSERT_STRING_EQUAL(pub1->name, pubNames[i]);

        // create second instance of publisher
        Publisher *pub2 = createPublisher(pubNames[i], NULL);
        CU_ASSERT_PTR_NOT_NULL_FATAL(pub2);
        CU_ASSERT_STRING_EQUAL(pub2->name, pubNames[i]);

        // verify they are the same instance
        CU_ASSERT_PTR_EQUAL(pub1, pub2);
    }
}

/**
 * Test Journal functions for local allocation
 */
static void test_journal_local(void) {
    const char* jourPubNames[5] = {
        "National Geographic Society", "Time", "Science Service", "Sunset", "Life"};
    const char* jourNames[5] = {
        "jour National Geographic Society", "jour Time", "jour Science Service", " jour Sunset", "jour Life"};
    const Issn jourIssn[5] = {
        12345678, 23456789, 34567890, 45678901, 56789012};

    // test local journal
    for (int i = 0; i < 5; i++) {
        // create publisher first
        Publisher* pub = createPublisher(jourPubNames[i], NULL);

        Journal j1, j2;

        // create local instance of journals
        Journal *jour1 = createJournal(jourIssn[i], jourNames[i], pub, &j1);
        CU_ASSERT_PTR_NOT_NULL_FATAL(jour1);
        CU_ASSERT_PTR_EQUAL(jour1, &j1);
        CU_ASSERT_STRING_EQUAL(jour1->name, jourNames[i]);
        CU_ASSERT_EQUAL(jour1->issn, jourIssn[i]);
        CU_ASSERT_PTR_EQUAL(jour1->publisher, pub);

        // create second instance of journals
        Journal *jour2 = createJournal(jourIssn[i], jourNames[i], pub, &j2);
        CU_ASSERT_PTR_NOT_NULL_FATAL(jour2);
        CU_ASSERT_PTR_EQUAL(jour2, &j2);
        CU_ASSERT_STRING_EQUAL(jour2->name, jourNames[i]);
        CU_ASSERT_EQUAL(jour2->issn, jourIssn[i]);
        CU_ASSERT_PTR_EQUAL(jour2->publisher, pub);

        // verify they are different
        CU_ASSERT_PTR_NOT_EQUAL(jour1, jour2);
    }
}

/**
 * Test Journal functions for dynamic allocation
 */
static void test_journal_dynamic(void) {
    const char* jourPubNames[5] = {
        "National Geographic Society", "Time", "Science Service", "Sunset", "Life"};
    const char* jourNames[5] = {
        "jour National Geographic Society", "jour Time", "jour Science Service", " jour Sunset", "jour Life"};
    const Issn jourIssn[5] = {
        12345678, 23456789, 34567890, 45678901, 56789012};

    for (int i = 0; i < 5; i++) {
        // create publisher first
        Publisher* pub = createPublisher(jourPubNames[i], NULL);

        // create instance of journal
        Journal *jour1 = createJournal(jourIssn[i], jourNames[i], pub, NULL);
        CU_ASSERT_PTR_NOT_NULL_FATAL(jour1);
        CU_ASSERT_STRING_EQUAL(jour1->name, jourNames[i]);
        CU_ASSERT_EQUAL(jour1->issn, jourIssn[i]);
        CU_ASSERT_PTR_EQUAL(jour1->publisher, pub);

        // create second instance of journal
        Journal *jour2 = createJournal(jourIssn[i], jourNames[i], pub, NULL);
        CU_ASSERT_PTR_NOT_NULL_FATAL(jour2);
        CU_ASSERT_STRING_EQUAL(jour2->name, jourNames[i]);
        CU_ASSERT_EQUAL(jour2->issn, jourIssn[i]);
        CU_ASSERT_PTR_EQUAL(jour2->publisher, pub);

        // verify getJournalByIssn
        Journal* j3 = malloc(sizeof(Journal*));
        j3 = getJournalByIssn(jourIssn[i]);
        CU_ASSERT_PTR_NOT_NULL_FATAL(j3);
        CU_ASSERT_PTR_EQUAL(j3, jour1);
        CU_ASSERT_PTR_EQUAL(j3, jour2);

        // verify they are the same instance
        CU_ASSERT_PTR_EQUAL(jour1, jour2);
    }
}

/**
 * Unit test driver
 *
 * @return test error code
 */
static CU_ErrorCode test_all_local(void) {
    // initialize the CUnit test registry – only once per application
    CU_initialize_registry();

    // add a suite to the registry with no init or cleanup
    CU_pSuite pSuite = CU_add_suite("test_all_local", NULL, NULL);

    // add the tests to the suite
    CU_add_test(pSuite, "issn test", test_issn);
    CU_add_test(pSuite, "test_publisher_local", test_publisher_local);
    CU_add_test(pSuite, "test_publisher_dynamic", test_publisher_dynamic);
    CU_add_test(pSuite, "test_journal_local", test_journal_local);
    CU_add_test(pSuite, "test_journal_dynamic", test_journal_dynamic);

    // run all suites using the basic interface that echoes to the console in this example
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // display information on failures that occurred
    CU_basic_show_failures(CU_get_failure_list());

    // Clean up registry and return status
    CU_cleanup_registry();
    return CU_get_error();
}

/**
* Main program to invoke test functions
*
* @return the exit status of the unit tests
*/
int main(void) {
    // test all the functions
    CU_ErrorCode code = test_all_local();
    return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}

