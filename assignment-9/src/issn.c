/*
 * issn.c
 * This file contains the definition of functions that
 * convert from Issn to string and string to Issn.
 *
 * Assignment 9
 * CS 5001, Fall 2017
 * Northeastern University Silicon Valley
 */

#include "issn.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Declaration of an invalid ISSN */
const Issn NO_ISSN = 0;

/**
 * Calculate the checksum digit
 *
 * @param issn 7-digit issn number
 * @return character of the check sum digit, if issn is not valid, return 0
 */
static char getCheckSumDigit(unsigned int issn) {
    /**
     * Calculate the sum of the first seven digits of the ISSN multiplied by
     * its position in the number, counting from the right—that is, 8, 7, 6, 5,
     * 4, 3, and 2, respectively:
     */
    int sum = 0;
    for (int i = 2; i < 9; i++) {
        sum += (issn % 10) * i;
        issn /= 10;
    }

    return sum % 11 == 0 ? '0' : (sum % 11 == 1 ? 'X' : 11 - (sum % 11) + '0');
}

/**
 * Converts an Issn to a string.
 * @param issn an Issn
 * @param issnStr the result string of at least 10 characters.
 * @return a pointer to the result string representing the ISSN
 */
char *issnToString(Issn issn, char *issnStr) {
    // make use of underlying uint32_t type of ISSN internally
    sprintf(issnStr, "%04u-%03u%c",  issn/1000, issn%1000, getCheckSumDigit(issn));
    return issnStr;
}

/**
 * Parses a string representing an ISSN and returns the
 * corresponding Issn.
 * @param issnStr the string representing asn ISSN
 * @return an Issn or the constant NO_ISSN if the input
 *   does not represent a valid ISSN string.
 */
Issn parseIssn(const char *issnStr) {
    unsigned int upper, lower;
    char issn[20];
	if (sscanf(issnStr, "%04u-%03u", &upper, &lower) == 2
	        && strcmp(issnToString((upper%10000)*1000 + (lower%1000), issn), issnStr) == 0)
	    return (upper%10000)*1000 + (lower%1000);
	return NO_ISSN;
}


