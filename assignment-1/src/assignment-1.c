/*
 ============================================================================
 Name        : assignment-1.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : Define and initialize the following variables with the
 appropriate type and scope. For each variable, provide a
 printf() statement that prints the name of the variable, its
 value, and the size of the variable in bytes.
 ============================================================================
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//A global unsigned integer variable globalUnsigned initialized by calculating the square of 3
unsigned int globalUnsigned = 3 * 3;
//A global floating point constant globalPI initialized to 3.14159
const float globalPI = 3.14159;

/**
 * Define and initialize the following variables with the appropriate type and scope.
 * For each variable, provide a printf() statement that prints the name of the variable, its value,
 * and the size of the variable in bytes.
 *
 * @return program status EXIT_SUCCESS
 */
int main(void) {
    //A local boolean variable localBool initialized to the logical expression globalUnsigned < globalPI
    bool localBool = globalUnsigned < globalPI;
    //A local int variable localInt initialized to the ratio of sum 2+4+5 divided by 3
    int localInt = (2 + 4 + 5) / 3;
    //A local short integer variable localShort that is the remainder of 11 with 3
    short localShort = 11 % 3;
    //A local long variable localLong that is 3 times the value of localInt plus the value of localShort.
    long localLong = localInt * 3 + localShort;
    //A local double precision floating point variable localDouble initialized to the ratio of 1.0 divided by -10.0
    double localDouble = 1.0 / -10.0;
    //A character variable initialized to 'Z'.
    char character = 'Z';

    //prints the name of the variable, its value, and the size of the variable in bytes.
    printf("globalUnsigned, the value is %u, and the size is %lu bytes.\n",
            globalUnsigned, sizeof(globalUnsigned));
    printf("globalPI, the value is %f, and the size is %lu bytes.\n", globalPI,
            sizeof(globalPI));
    printf("localBool, the value is %d, and the size is %lu bytes.\n",
            localBool, sizeof(localBool));
    printf("localInt, the value is %d, and the size is %lu bytes.\n", localInt,
            sizeof(localInt));
    printf("localShort, the value is %d, and the size is %lu bytes.\n",
            localShort, sizeof(localShort));
    printf("localLong, the value is %ld, and the size is %lu bytes.\n",
            localLong, sizeof(localLong));
    printf("localDoublet, the value is %f, and the size is %lu bytes.\n",
            localDouble, sizeof(localDouble));
    printf("character, the value is %c, and the size is %lu bytes.\n",
            character, sizeof(character));

    return EXIT_SUCCESS;
}
