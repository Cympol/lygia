// HEADERS: -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "arraylist.h"

// FUNCTIONS: -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// CONSTRUCTOR;.
arraylist *arraylist_make(size_t capacity, size_t type_size){
	// Allocates memory for the list;
	arraylist *new_list = malloc(sizeof(arraylist));
	if(new_list) { // If the list is NULL, returns it as is. Else, allocates for data;
		new_list->data = malloc(capacity * type_size);
		if (new_list->data) { // If NULL, frees the allocated list and sets it to NULL
			new_list->type_size = type_size;
			new_list->capacity  = capacity;
			new_list->size      = 0;
		} else {
			free(new_list);
			new_list = NULL;
		}
	}
	return new_list;
}

// DESTRUCTOR;
bool arraylist_drop(arraylist *list) {
	if (list->data) {
		free(list->data);
		list->data = NULL;
		return true;
	}
	return false;
}

bool arraylist_set_capacity(arraylist *list, size_t size) {
	uint8_t *temp = realloc(list->data, list->type_size * size);
	if (temp) {
		list->capacity = size;
		if (size < list->size) {
			list->size = size;
		}
		return true;
	}
	return false;
}

// RETURNS FIRST VALUE OF LIST, NULL IF EMPTY;
void *arraylist_first(arraylist *list){
	return list->size < 1 ? NULL : list->data;
}

// RETURNS LAST VALUE OF LIST, NULL IF EMPTY;
void *arraylist_last(arraylist *list){
	return list->size < 1 ? NULL : (list->data + list->type_size * (list->size-1));
}

// ADDS VALUE TO END OF LIST;
bool arraylist_push(arraylist *list, void *value) {
	// Resize list If the list reaches full capacity,
	if (list->capacity <= list->size) {
		// If resizing arraylist fails, then returns false;
		if (!arraylist_set_capacity(list, list->capacity * 2)) {
			return false;
		}
	}
	++list->size; // Increase the size of the list.
	memcpy( //Copies the value to the end of the list.
		list->data + (list->type_size * (list->size-1)), //Adds up to the last index of the list
		value, 										 //Value to be copied
		list->type_size 							 //Size of the element
	);
	return true;
}

// REMOVES LAST VALUE OF LIST, IF THERE IS ONE;
bool arraylist_pop(arraylist *list) {
	if (list->size > 0) {
		--list->size;
		return true;
	}
	return false;
}

// GET VALUE FROM INDEX, RETURNS NULL IF INDEX OUT OF BOUNDS;
void *arraylist_get(arraylist *list, size_t index) {
	return index < list->size ? (list->data + list->type_size * index) : NULL;
}

// CHANGES VALUE OF A CERTAIN ELEMENT OF LIST, DOESN'T IF OUT OF BOUNDS;
bool arraylist_set(arraylist *list, size_t index, void *value) {
	if (index < list->size) {
		memcpy(list->data + (list->type_size * index), value, list->type_size);
		return true;
	}
	return false;
}

// ADDS AN ELEMENT TO A CERTAIN INDEX OF THE LIST;
bool arraylist_add(arraylist *list, size_t index, void *value){
	if (index < list->size) {
		// Resize list If the list reaches full capacity,
		if (list->capacity <= list->size) {
			// If resizing arraylist fails, then returns false;
			if (!arraylist_set_capacity(list, list->capacity * 2)) {
				return false;
			}
		}
		++list->size; // Increases size of list
		// Shifts data to the right, so insertion of value is possible
		memmove(
			list->data + list->type_size * (index + 1),  //Dest: The index to be added
			list->data + list->type_size * index,      //Src:  One space behind of the index
			list->type_size * (list->size - index - 1) //Size: It works
		);
		// Inserts the value in the desired index
		memcpy(list->data + (list->type_size * index), value, list->type_size);
		return true;
	}
	return false;
}

bool arraylist_del(arraylist *list, size_t index) {
	if (index < list->size) {
		// Shifts all data to the left by one:
		memmove(
			list->data + list->type_size * index,       //Dest: The index to be removed
			list->data + list->type_size * (index + 1), //Src:  One space ahead of the index
			list->type_size * (list->size - index - 1)  //Size: It works
		);  
		--list->size; // Decreases list size by one
		return true;
	}
	return false;
}