#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__
// HEADERS: -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
// ARRAYLIST DEFINITION: -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

typedef struct { //arraylist
	uint8_t *data;
	size_t   type_size;

	size_t   capacity;
	size_t   size;
} arraylist;

// FUNCTION DECLARATIONS: -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
arraylist *arraylist_make(size_t capacity, size_t type_size);

bool  arraylist_drop(arraylist *list);
bool  arraylist_set_capacity(arraylist *list, size_t size);

void *arraylist_first(arraylist *list);
void *arraylist_last(arraylist *list);

bool  arraylist_pop(arraylist *list);
bool  arraylist_push(arraylist *list, void *value);

void *arraylist_get(arraylist *list, size_t index);
bool  arraylist_set(arraylist *list, size_t index, void *value);

bool  arraylist_del(arraylist *list, size_t index);
bool  arraylist_add(arraylist *list, size_t index, void *value);

#endif //__ARRAYLIST_H__