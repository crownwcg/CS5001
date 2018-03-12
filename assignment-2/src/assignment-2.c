/*
 ============================================================================
 Name        : assignment-2.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : A program that calls 3 functions with test data and prints the
 results returned by these functions.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** count the number of times that the function problem1 has been called */
unsigned int problem1Count = 0;
/**
 * This function counts the number of times the function is called.
 * If called with false, the function returns 0.
 * If called with true, the function resets problem1Count to 0 and returns
 * the number of times the function was called since the last time it was reset.
 *
 * @param reset a boolean parameter to set the status
 * @return 0 when called with false or the number of times the function was
 *  		  called since the last time it was reset
 */
unsigned int problem1(bool reset) {
    if (reset) {
        int number = problem1Count; //record the problem1Count
        problem1Count = 0;          //resets problem1Count to 0
        return number;
    } else {
        problem1Count++;
        return 0;
    }
}

/**
 * The function computes the sum of the first n natural numbers using a for loop
 * whose index varies from 1 to n.
 *
 * @param n the first n natural numbers to compute
 * @return the sum of the first n natural numbers
 */
unsigned int sumN(unsigned int n) {
    int sumN = 0;

    for (int i = 1; i <= n; i++) {
        sumN += i;
    }

    return sumN;
}

/**
 * The function takes a month number between 1 (January) and 12 (December),
 * to compute the number of days in any month (assuming 28 for February).
 *
 * @param month a month number between 1 (January) and 12 (December)
 * @return the number of days in any month or 0 if the input value is not valid
 */
unsigned int daysInMonth(unsigned int month) {
    unsigned int numDays;

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        numDays = 30;
        break;
    case 2:
        numDays = 28;
        break;
    default:
        numDays = 0;
        break;
    }

    return numDays;
}

/**
 * This function calls the functions above with test data and prints the results
 * returned by the functions.
 *
 * @return program status EXIT_SUCCESS
 */
int main(void) {
    /** test of problem1 function. */
    printf("This is the test of problem1 function:\n");
    int i = 1;
    while (i < 5) {
        printf("The return is %d when called by false. The problem1Count is %d.\n",
                problem1(false), problem1Count);
        i++;
    }
    printf("The return is %d when called by true. The problem1Count is %d.\n\n",
            problem1(true), problem1Count);

    /** test of sumN function. */
    printf("This is the test of sumN function:\n");
    int n = 55;
    printf("The sum of 1 to %d is %d, while using the formula n*(n+1)/2, the sum is %d.\n\n",
            n, sumN(n), n * (n + 1) / 2);

    /** test of daysInMonth function. */
    printf("This is the test of daysInMonth function:\n");
    int k = 1;
    while (k <= 13) {
        printf("%d has %d days.\n", k, daysInMonth(k));
        k++;
    }
    printf("\n");

    return EXIT_SUCCESS;
}
