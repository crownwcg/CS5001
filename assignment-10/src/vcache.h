/*
 * vcache.h
 * This file declares functions to operate on a Vcache, which
 * is a cache of void* pointers. Pointers to a particular type
 * can be added to the cache, and must be cast back to the
 * appropriate pointer type before being dereferenced.
 */

#ifndef VCACHE_H_
#define VCACHE_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * Vcache represents a variable size cache of void* items.
 * Pointers to a particular type can be added to the cache,
 * and must be cast back to the appropriate pointer type
 * before being dereferenced.
 */
typedef struct Vcache Vcache;

/**
 * Creates and returns a variable size cache instance.
 * @return a new variable size cache
 */
Vcache *createVcache(void);

/**
 * Determines whether cache contains the item.
 * @param vc pointer to a Vcache
 * @param item pointer to an item to check
 * @returns true if contains the item, false otherwise
 */
bool containsVcacheItem(Vcache *vc, void *item);

/**
 * Add an item to the cache.
 * @param vc pointer to a Vcache
 * @param the item to add
 * @return true item added to cache or false if item
 * 	already in cache (cannot add NULL pointer to cache)
 */
bool addVcacheItem(Vcache* vc, void *item);

/**
 * Get a pointer to the item at the specified cache index;
 * @param vc pointer to a Vcache
 * @param index 0 based index
 * @return pointer to item at index or NULL if index out of bounds
 */
void *getVcacheItemAt(Vcache *vc, size_t index);

/**
 * Returns the number of items in the cache;
 * @param vc pointer to a Vcache
 * @return the number of items in the cache
 */
size_t getVcacheSize(Vcache *vc);

#endif /* VCACHE_H_ */
