/*
 * issn.h
 * This file contains the declarations of functions that
 * convert from Issn to string and string to Issn.
 *
 * Assignment 9
 * CS 5001, Fall 2017
 * Northeastern University Silicon Valley
 */

#ifndef ISSN_H_
#define ISSN_H_

#include <stdlib.h>

/** Representation of a 7-digit ISSN */
typedef uint32_t Issn;

/** Declaration of an invalid ISSN */
const Issn NO_ISSN;

/**
 * Converts an Issn to a string.
 * @param issn an Issn
 * @param issnStr the result string of at least 10 characters.
 * @return a pointer to the result string representing the ISSN
 */
char *issnToString(Issn issn, char *issnStr);

/**
 * Parses a string representing an ISSN and returns the
 * corresponding Issn.
 * @param issnStr the string representing an ISSN
 * @return an Issn or the constant NO_ISSN if the input
 *   does not represent a valid ISSN string.
 */
Issn parseIssn(const char *issnStr);


#endif /* ISSN_H_ */
