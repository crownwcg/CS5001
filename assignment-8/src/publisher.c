/*
 * publisher.c
 *
 *  Definition of a Publisher
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */
#include "publisher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** size of allocated publisher pointer array */
static size_t PUBLISHERS_SIZE = 0;

/** pointer to allocated publisher pointer array */
static Publisher **publishers = NULL;

/** Initialize publishers cache. Call from operations that access it */
static void initPublishersCache(void) {
	if (publishers == NULL) {
		PUBLISHERS_SIZE = 4; // size of publishers array
		publishers = malloc(PUBLISHERS_SIZE * sizeof(Publisher *));
		publishers[0] = NULL; // null terminate array;
	}
}

/**
  * Print a Publisher
  * @param publisher the publisherto print
  */
void printPublisher(const Publisher *publisher) {
	printf("Publisher: ’%s’\n",  publisher->name);
}

/**
  * Get a Publisher by its name
  * @param name the publisher name
  * @param pub pointer to space for returned Publisher, or NULL to use saved publishers array
  * @return pointer to pub struct, or to saved publisher if pub is NULL
  * 	   (NULL if could not save new publisher to publishers array)
  */
Publisher *createPublisher(const char *name, Publisher* pub) {
	if (pub == NULL) {
		initPublishersCache();

		// find publisher in array
		int pindex = 0;
		for ( ; publishers[pindex] != NULL; pindex++) {   // while not at sentinel entry
			if (strcmp(publishers[pindex]->name, name) == 0) {
				return publishers[pindex];  	// return matching publisher
			}
		}

		// if publisher not found, allocate new struct and add to array
		if (pindex+1 >=  PUBLISHERS_SIZE)  {
			PUBLISHERS_SIZE *= 2;	// double size of publishers array
			publishers = realloc (publishers, PUBLISHERS_SIZE * sizeof(Publisher*));
		}
		pub = malloc( sizeof(Publisher) );	// allocate storage for new publisher
		publishers[pindex] = pub;	// add pointer to new Publisher to array;
		publishers[++pindex] = NULL;	// add null pointer after new one;
	}
    	strcpy(pub->name, name);
	return pub;
}

/**
 * Get a publisher in the publisher cache by name
 *
 * @param name the name of the publisher
 * @return the Publisher or NULL if not in cache
 */
Publisher *getPublisherByName(const char* name) {
	initPublishersCache();

	// find publisher in array
	int pindex = 0;
	for ( ; publishers[pindex] != NULL; pindex++) {   // while not at sentinel entry
		if (strcmp(publishers[pindex]->name, name) == 0) {
			return publishers[pindex];  	// return matching publisher
		}
	}
	return NULL;
}
