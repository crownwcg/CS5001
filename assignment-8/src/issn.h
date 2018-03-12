/*
 * issn.h
 *	Declarations for an Issn that represents a journal ISSN,
 *	usually displayed as NNNN-NNNC
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#ifndef ISSN_H_
#define ISSN_H_

#include <stdio.h>
#include <inttypes.h>

/** Represents an 8-digit journal id: NNNN-NNNN */
typedef uint32_t Issn;

/** Sentinel value used when the ISSN is unknown */
extern const Issn ISSN_UNKNOWN;

/**
  * Get string representation of ISSN
  * @param issn the ISSN value
  * @param issnChars array to receive the ISSN characters (OUT)
  * @return pointer to ISSN chars
  */
char *issnToString(Issn issn, char issnChars []);
/**
  * Parse a string representation of an Issn
  * @param issnChars array with the input Issn string
  * @return the Issn or ISSN_UNKNOWN if string not valid  Issn string
  */
Issn parseIssn(const char issnChars []);

#endif /* ISSN_H_ */
