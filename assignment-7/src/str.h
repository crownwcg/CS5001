/*
 * dupstr.h
 *
 *  Created on: 2017年10月3日
 *      Author: Crown
 */

#ifndef STR_H_
#define STR_H_

/**
 * Creates and returns a pointer to a duplicate string that is dynamically allocated
 * and initialized from the input string.
 *
 * @param str input string
 * @return a pointer to a duplicate string.
 */
char *dupStr(const char *str);

/**
 * Splits a string into a list of strings at the delimiter character ch. It also dynamically
 * allocates storage for a copy of the input string, and replaces each occurence of ch in the
 * copy by the null character ('\0'). It also sets the character after the final null character
 * in the copy to the character '\377' (octal), to mark the end of the list.
 *
 * @param str input string
 * @param ch character to split
 * @return a pointer to a list of strings.
 */
char *splitString(const char *str, char ch);

/**
 * Given a pointer to a split string list.
 *
 * @param str a string list
 * @return a pointer to the beginning of the next
 *         string in the list, or NULL if there is no next string
 */
char *nextSplitString(char *str);

/**
 * Compute the number of strings in the list including the current one as a size_t
 *
 * @param str a string list
 * @return number of string in the list
 */
size_t splitStringSize(char *str);

#endif /* STR_H_ */
