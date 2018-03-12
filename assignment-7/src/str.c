/*
 * dupstr.c
 *
 *  Created on: 2017年10月3日
 *      Author: Crown
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "str.h"

/**
 * Creates and returns a pointer to a duplicate string that is dynamically allocated
 * and initialized from the input string.
 *
 * @param str input string
 * @return a pointer to a duplicate string.
 */
char *dupStr(const char *str) {
    if (str == NULL)
        return NULL;

    char *dup = malloc(sizeof(char) * (strlen(str) + 1));
    if (dup != NULL)
        strcpy(dup, str);

    return dup;
}

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
char *splitString(const char *str, char ch) {
    if (str == NULL)
        return NULL;
    char *dup = malloc((strlen(str) + 2) * sizeof(char));
    const char *strp = str;
    char *dupp = dup;
    do {
        *dupp++ = (*strp == ch) ? '\0' : *strp;
    } while (*strp++ != '\0');
    *dupp = '\377';

    return dup;
}

/**
 * Given a pointer to a split string list.
 *
 * @param str a string list
 * @return a pointer to the beginning of the next
 *         string in the list, or NULL if there is no next string
 */
char *nextSplitString(char *str) {
    if (str == NULL)
        return NULL;
    char *strp = str;
    strp += strlen(str) + 1;
    return *strp == '\377' ? NULL : strp;
}

/**
 * Compute the number of strings in the list including the current one as a size_t
 *
 * @param str a string list
 * @return a pointer to the beginning of the next
 *         string in the list, or NULL if there is no next string
 */
size_t splitStringSize(char *str) {
    size_t size = 0;
    if (str != NULL) {
        size++;
        while ((str = nextSplitString(str)) != NULL)
            size++;
    }
//    char *strp = str;
//    while (*strp != '\377' || strp != NULL) {
//        if (*strp == '\0')
//            size++;
//        str++;
//    }
    return size;
}

