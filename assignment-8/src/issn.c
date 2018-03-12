/*
 * issn.c
 *
 *	Definition of an ISSN that represents a journal ISSN, usually
 *	displayed as NNNN-NNNNC
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#include "issn.h"

/** Sentinel value used when the ISSN is unknown */
const Issn ISSN_UNKNOWN = 0;	// value is not a valid ISSN

/**
  * Get string representation of ISSN
  * @param issn the ISSN value
  * @param issnChars array to receive the ISSN characters (OUT)
  * @return pointer to ISSN chars
  */
char *issnToString(Issn issn, char issnChars []) {  // char  *issnChars
	// make use of underlying uint32_t type of ISSN internally
 	sprintf(issnChars, "%04d-%04d",  issn/10000, issn%10000);
	return issnChars;
}

/**
  * Parse a string representation of an Issn
  * @param issnChars array with the input Issn string
  * @return the Issn or ISSN_UNKNOWN if string not valid  Issn string
  */
Issn parseIssn(const char issnChars []) {
	unsigned int upper, lower;
	// make use of underlying uint32_t type of ISSN internally
 	if (sscanf(issnChars, "%04d-%04d", &upper, &lower) != 2) {
		return ISSN_UNKNOWN;
	}
	return (upper%10000)*10000 + (lower%10000);
}

