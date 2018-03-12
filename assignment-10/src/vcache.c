/*
 * vcache.c
 *
 * This file defines functions to operate on a Vcache, which
 * is a cache of void* pointers. Pointers to a particular type
 * can be added to the cache, and must be cast back to the
 * appropriate pointer type before being dereferenced.
 */

#include "vcache.h"

/**
 * This struct represents a variable size cache of void* items.
 * The type is opaque outside of this file.
 */
struct Vcache {
	/** capacity of allocated cache array */
	size_t capacity;
	/** current size of allocated cache */
	size_t size;
	/** pointer to allocated cache pointer array */
	void **cache;
};

/** initial size of Vcache cache array */
static const size_t INITIAL_CAPACITY = 4;

/**
 * Create a variable size cache.
 * @return pointer to a new Vcache instance
 */
Vcache *createVcache(void) {
    /** allocate memory to initiate a new Vcache instance */
    Vcache *vc   = (Vcache *)malloc(sizeof(Vcache));
    vc->capacity = INITIAL_CAPACITY;
    vc->size     = 0;
    vc->cache    = (void **)malloc(sizeof(void *) * vc->capacity);
    vc->cache[0] = NULL;

    return vc;
}

/**
 * Determines whether cache contains the item.
 * @param vc pointer to a Vcache
 * @param item pointer to the item to check
 * @returns true if contains the item, false otherwise
 */
bool containsVcacheItem(Vcache *vc, void *item) {
    if (vc == NULL || item == NULL || vc->cache == NULL)
        return false;

    size_t index = 0;
    for (; vc->cache[index] != NULL; index++) {
        if (vc->cache[index] == item)
            return true;
    }
    return false;
}

/**
 * Add an item to the cache.
 * @param vc pointer to a Vcache
 * @param the item to add
 * @return true item added to cache or false if item
 * 	already in cache (cannot add NULL pointer to cache)
 */
bool addVcacheItem(Vcache *vc, void *item) {
    if (item == NULL || vc == NULL || containsVcacheItem(vc, item))
        return false;

    /** if size exceeds capacity, allocate new memory */
    if (vc->size + 1 >= vc->capacity) {
        vc->capacity *= 2;
        vc->cache = realloc(vc->cache, sizeof(void *) * vc->capacity);
    }

    /** add item to the array */
    vc->cache[vc->size] = item;
    vc->cache[++vc->size] = NULL;

    return true;
}

/**
 * Get item at the cache index;
 * @param vc pointer to a Vcache
 * @param index 0 based index
 * @return pointer to item at index or NULL if index out of bounds
 */
void *getVcacheItemAt(Vcache *vc, size_t index) {
    if (vc == NULL || index > vc->size - 1 || vc->cache == NULL)
        return NULL;
    return vc->cache[index];
}

/**
 * Returns the number of items in the cache;
 * @param vc pointer to a Vcache
 * @return the number of items in the cache
 */
size_t getVcacheSize(Vcache *vc) {
    if (vc != NULL)
        return vc->size;
    return 0;
}
