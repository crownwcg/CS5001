/*
 * issn_test.c
 * Test suite function for Journal.
 *
 *  Created on: Oct 3, 2017
 *  Author: philip gust
 */

#include <stdio.h>
#include <stdlib.h>
#include "journal.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/**
 * Test Journal functions for local allocation.
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
 * Test Journal functions for dynamic allocation.
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
 * Add suite for Journal unit tests
 */
void journal_test(void) {
	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("journal_test", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_journal_local", test_journal_local);
	CU_add_test(pSuite, "test_journal_dynamic", test_journal_dynamic);
}
