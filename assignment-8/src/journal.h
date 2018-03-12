/*
 * journal.h
 *
 * Declaration of a Journal.
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#ifndef JOURNAL_H_
#define JOURNAL_H_

#include "issn.h"
#include "publisher.h"

/** Struct that defines a Journal */
typedef struct  Journal {
	char name[100];			// journal name
	Issn issn;				// ISSN of journal
	Publisher *publisher;	// pointer to publisher
} Journal;
/**
  * Print a Journal
  * @param journal the journal to print
  */
void printJournal(const Journal *journal);

/**
  * Create a journal from its information
  * @param issn the journal Issn
  * @param name the journal name
  * @param pub the Publisher
  * @param journal pointer to space for returned Journal, or NULL to use saved journals array
  * @return pointer to journal struct, or to saved journal if journal is NULL
  * 	   (NULL if not defined)
  */
Journal* createJournal(Issn issn, const char* name, Publisher *pub, Journal *journal);
/**
  * Get a journal from its issn from the journals cache
  * @param issn the journal Issn
  * @return pointer to saved journal (NULL if not in journals array)
  */
Journal* getJournalByIssn(Issn issn);


#endif /* JOURNAL_H_ */
