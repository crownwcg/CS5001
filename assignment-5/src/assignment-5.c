/*
 ============================================================================
 Name        : assignment-6.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : assignment-6
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Takes two int parameters rows and cols and a 2D array of double values.
 * Print the values of the array in row-major order, one row per line, with
 * the values on each line separated by ',' characters.
 *
 * @param array the array to print
 * @param rows  array's rows
 * @param cols  array's cols
 */
void print2DByRows(const int rows, const int cols, const double array[][cols]) {
    for (int i = 0; i < rows; i++) {
        char *arr = "";
        for (int j = 0; j < cols; j++) {
            printf("%s%.2f", arr, array[i][j]);
            arr =", ";
        }
        printf("\n");
    }
}

/*
 * Takes two int parameters rows and cols and a 2D array of double values.
 * Print the values of the array in column-major order, one column per line,
 * with the values on each line separated by ',' characters.
 *
 * @param array the array to print
 * @param rows  array's rows
 * @param cols  array's cols
 */
void print2DByCols(const int rows, const int cols, const double array[][cols]) {
    for (int i = 0; i < cols; i++) {
        char *arr = "";
        for (int j = 0; j < rows; j++) {
            printf("%s%.2f", arr, array[j][i]);
            arr =", ";
        }
        printf("\n");
    }
}

/**
 * Takes two int parameters rows and cols and a pointer to an array of
 * double values that representa 2D array in row major order. Print the values
 * of the array in row-major order, one row per line, with the values on each
 * line separated by ',' characters.
 *
 * @param array pointer to the array to print
 * @param rows  array's rows
 * @param cols  array's cols
 */
void printByRows(const int rows, const int cols, const double* array) {
    assert(array != NULL);

    for (int i = 0; i < rows; i++) {
        char *arr = "";
        for (int j = 0; j < cols; j++) {
            printf("%s%.2f", arr, *array++);
            arr = ", ";
        }
        printf("\n");
    }
}

/**
 * Takes two double parameters rows and cols and a pointer to an array of
 * double values that representa 2D array in row major order. Print the values
 * of the array in column-major order, one column per line, with the values on
 * each line separated by ',' characters.
 *
 * @param array pointer to the array to print
 * @param rows  array's rows
 * @param cols  array's cols
 */
void printByCols(const int rows, const int cols, const double* array) {
    assert(array != NULL);

    for (int i = 0; i < cols; i++,array++) {
        char *arr = "";
        for (int j = 0; j < rows; j++) {
            printf("%s%.2f", arr, *(array+cols*j));
            arr = ", ";
        }
        printf("\n");
    }
}

/**
 * Enum type MonthOfYear that defines the months of the year.
 */
typedef enum {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} MonthOfYear;
/**
 * Takes a MonthOfYear and returns a pointer to a const char* that represents the
 * month name.
 *
 * @param month a MonthOfYear
 * @return a pointer to a const char* that represents the month name.
 */
const char* getMonthName(const MonthOfYear month) {
    // static makes it only initiate once through the program
    static const char* monthOfYear[12] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

    return (month < Jan || month > Dec) ? NULL : monthOfYear[month];
}

/**
 * Enum type FuzzyBool that defines three values: YES, NO, and MAYBE.
 */
typedef enum FuzzyBool {NO, MAYBE, YES} FuzzyBool;
/**
 * Takes two FuzzyBool values and returns YES if either value is YES,
 * NO if both values are NO and MAYBE otherwise.
 *
 * @param b1 one of the FuzzyBool values
 * @param b2 one of the FuzzyBool values
 * @return YES if either value is YES, NO if both values are NO and MAYBE otherwise.
 */
FuzzyBool fuzzyOR(const FuzzyBool b1, const FuzzyBool b2) {
    return b1 > b2 ? b1 : b2;
}
/**
 * Takes two FuzzyBool values and returns YES if both values are YES,
 * NO if either value is NO and MAYBE otherwise.
 *
 * @param b1 one of the FuzzyBool values
 * @param b2 one of the FuzzyBool values
 * @return YES if both values are YES, NO if either value is NO and MAYBE otherwise.
 */
static FuzzyBool fuzzyAND(const FuzzyBool b1, const FuzzyBool b2) {
    return b1 < b2 ? b1 : b2;
}
static const char* toString(FuzzyBool b) {
    static const char* bools[3] = {"NO", "MAYBE", "YES"};
    return bools[b];
}

/** 8-bit unsigned quantity */
typedef unsigned char unit8_t;
/** Typedef Color as a uint8_t. */
typedef unit8_t Color;
/** Define a struct RGB that has red, green, and blue Color fields. */
typedef struct RGB {
    Color red;
    Color green;
    Color blue;
} RGB;
/**
 * Initializes the RGB struct and returns a pointer to it.
 *
 * @param red color red to set
 * @param green color green to set
 * @param blue color blue to set
 * @return a pointer to struct RGB.
 */
RGB* setRGBColors(const Color red, const Color green, const Color blue, RGB* rgb) {
    assert(rgb != NULL);

    rgb->red   = red;
    rgb->green = green;
    rgb->blue  = blue;

    return rgb;
}
/**
 * Print RGB's red, green, and blue values on a single line using hexidecimal format.
 */
void printRGB(const RGB* rgb) {
    assert(rgb != NULL);
    printf("Color RGB: red:0x%x, green:0x%x, blue:0x%x.\n",
            rgb->red, rgb->green, rgb->blue);
}


/**
 * test of functions
 */
int main(void) {
    double array[4][3] = {{1,2,3},{4,5,6},{7,8,9}, {10,11,12}};

    /**
     * test of function print2DByRows
     */
    printf("Test of print2DByRows():\n");
    print2DByRows(4, 3, array);
    printf("\n");

    /**
     * test of function print2DByCols
     */
    printf("Test of print2DByCols():\n");
    print2DByCols(4, 3, array);
    printf("\n");

    double* p = (double*)array;
    /**
     * test of function printByCols
     */
    printf("Test of printByRows():\n");
    printByRows(4, 3, p);
    printf("\n");

    /**
     * test of function printByCols
     */
    printf("Test of printByCols():\n");
    printByCols(4, 3, p);
    printf("\n");

    /**
     * test of function getMonthName
     */
    printf("Test of getMonthName():\n");
    for (MonthOfYear month = Jan; month < 12; month++) {
        printf("%s\t", getMonthName(month));
    }
    printf("\n\n");

    /**
     * test of function fuzzyOR
     */
    printf("Test of fuzzyOR():\n");
    printf("Test of fuzzyAND():\n");
    printf("Bool:\t ");
    FuzzyBool bool = NO;
    for (; bool < 3; bool++) {
        printf("%s\t", toString(bool));
    }
    printf("\n        ________________________\n");
    for (FuzzyBool bool1 = NO; bool1 <= YES; bool1++) {
        printf("%s\t|", toString(bool1));
        for (FuzzyBool bool2 = NO; bool2 <= YES; bool2++) {
            printf("%s\t", toString(fuzzyOR(bool1, bool2)));
        }
        printf("\n");
    }
    printf("\n");

    /**
     * test of function fuzzyAND
     */
    printf("Test of fuzzyAND():\n");
    printf("Bool:\t ");
    bool = NO;
    for (; bool < 3; bool++) {
        printf("%s\t", toString(bool));
    }
    printf("\n        ________________________\n");
    for (FuzzyBool bool1 = NO; bool1 <= YES; bool1++) {
        printf("%s\t|", toString(bool1));
        for (FuzzyBool bool2 = NO; bool2 <= YES; bool2++) {
            printf("%s\t", toString(fuzzyAND(bool1, bool2)));
        }
        printf("\n");
    }
    printf("\n");

    /**
     * test of function setRGBColors and printRGB
     */
    printf("Test of setRGBColors() and printRGB():\n");
    RGB rgb;
    setRGBColors(25, 66, 79, &rgb);
    printf("Expected Color RGB: red 0x19, green 0x42, blue 0x4f.\nResults ");
    printRGB(&rgb);

    return EXIT_SUCCESS;
}
