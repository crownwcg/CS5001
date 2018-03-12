/*
 ============================================================================
 Name        : assignment-3.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : A program that calls 2 functions with test data and prints the
 results returned by these functions.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initializes all n elements of the input array to the specified value.
 *
 * @param size size of the input array
 * @param array input array
 * @param value specified value to initialize
 */
void initArray(unsigned int size, int array[], int value) {
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }

    return;
}

/**
 * Counts the number of words in the input string and return the count.
 *
 * @param str input string
 * @return the count as the function result
 */
unsigned int wordCount(char str[]) {
    if (str[0] == '\0')
        return 0;

    int count = 0;
    int index = 0;

    /** count the number when encountering the whitespace, and ignore multiple whitespace */
    while (str[++index] != '\0') {
        if (str[index] == ' ' && str[index - 1] != ' ')
            count++;
    }
    /** count the number in the end of string if the former character is not a whitespace */
    if (str[index] == '\0' && str[index - 1] != ' ')
        count++;

    return count;
}

/**
 * This function calls the functions above with test data and prints the results
 * returned by the functions.
 *
 * @return program status EXIT_SUCCESS
 */
int main(void) {
    /** This is the test of initArray function */
    printf("This is the test of initArray function:\n");
    int arr1[3], arr2[5];
    initArray(3, arr1, 45);
    initArray(5, arr2, 88);
    printf("initArray(3, arr2, 45), the result: {%d, %d, %d}.\n", arr1[0],
            arr1[1], arr1[2]);
    printf("initArray(5, arr3, 88), the result: {%d, %d, %d, %d, %d}.\n\n",
            arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);

    /** This is the test of wordCount function */
    printf("This is the test of wordCount function:\n");
    char str[5][25] = { "", "the", "two words", "the quick brown fox",
            " the quick  brown   fox " };
    for (int i = 0; i < 5; i++) {
        printf("There are %d words in \"%s\" whose length is %lu.\n",
                wordCount(str[i]), str[i], strlen(str[i]));
    }

    return EXIT_SUCCESS;
}
