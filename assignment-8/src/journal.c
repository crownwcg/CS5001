/*
 * journal.c
 *
 *  Definition of a Journal
 *
 *  Created on: Oct 31, 2017
 *  Author: philip gust
 */

#include "journal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**  Size of allocated journals pointer array */
static size_t JOURNALS_SIZE = 0;

/** pointer to allocated journals pointer array */
static Journal **journals = NULL;

/** Initialize journals cache. Call from operations that access it */
static void initJournalsCache(void) {
    if (journals == NULL) {
        JOURNALS_SIZE = 4;
        journals = malloc(JOURNALS_SIZE * sizeof(Journal *));
        journals[0] = NULL;
    }
}

/**
  * Print a Journal
  * @param journal the journal to print
  */
void printJournal(const Journal *journal) {
	char issnChars[10];
	char* issnString = issnToString(journal->issn, issnChars);
	printf("Name: ’%s’\n", journal->name);
	printf("ISSN: %s\n", issnString);
	printPublisher(journal->publisher);  // journal publisher pointer field
}

/**
  * Create a journal from its information
  * @param issn the journal Issn
  * @param name the journal name
  * @param pub the Publisher
  * @param journal pointer to space for returned Journal, or NULL to use saved journals array
  * @return pointer to journal struct, or to saved journal if journal is NULL
  * 	   (NULL if not defined)
  */
Journal* createJournal(Issn issn, const char* name, Publisher *pub, Journal *journal) {
    if (journal == NULL) {
        initJournalsCache();

        // find journals in array
        int jindex = 0;
        for (; journals[jindex] != NULL; jindex++) {
            if (journals[jindex]->issn == issn
                    && journals[jindex]->publisher == pub
                    && strcmp(journals[jindex]->name, name) == 0)
                return journals[jindex];
        }

        // if journal not found, allocate new struct and add to array
        if (jindex+1 >= JOURNALS_SIZE) {
            JOURNALS_SIZE *= 2; // double size of journals array
            journals = realloc(journals, JOURNALS_SIZE * sizeof(Journal *));
        }
        journal = malloc(sizeof(Journal *));
        journals[jindex] = journal;
        journals[++jindex] = NULL;
    }

    strcpy(journal->name, name);
    journal->publisher = pub;
    journal->issn = issn;

    return journal; // temporary
}

/**
  * Get a journal from its issn from the journals array
  * @param issn the journal Issn
  * @return pointer to saved journal (NULL if not in journals array)
  */
Journal* getJournalByIssn(Issn issn) {
    initJournalsCache();

    // find journals in array
    int jindex = 0;
    for ( ; journals[jindex] != NULL; jindex++) {   // while not at sentinel entry
        if (journals[jindex]->issn == issn) {
            return journals[jindex];      // return matching journal
        }
    }
	
    return NULL; // temporary
}
