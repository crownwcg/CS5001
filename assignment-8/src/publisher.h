/*
 * publisher.h
 *
 * Declaration of a Publisher that includes the publisher name.
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#ifndef PUBLISHER_H_
#define PUBLISHER_H_

/** Struct that defines a Publisher */
typedef struct {
    char name[100];
}Publisher;

/**
  * Print a Publisher
  * @param publisher the publisherto print
  */
void printPublisher(const Publisher *publisher);

/**
  * Create a Publisher
  * @param name the publisher name
  * @param pub pointer to space for returned Publisher, or NULL to
  * 	    use saved publishers array
  * @return pointer to pub struct, or to saved publisher if pub is NULL
  * 	   (NULL if could not save new publisher to publishers array)
  */
Publisher *createPublisher(const char *name, Publisher* pub);

/**
 * Get a publisher in the publisher cache by name
 * @param name the name of the publisher
 * @return the Publisher or NULL if not in cache
 */
Publisher *getPublisherByName(const char* name);

#endif /* PUBLISHER_H_ */
