#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define ALLOCATE(type, count)                                                  \
  (type *)reallocate(NULL, 0, sizeof(type) * (count))

// Makro do obliczania pojemności tablicy.
// Jeśli capacity jest mniejsze od 8 to zwracamy 8, w przeciwnym wypadku
// zwracamy capacity * 2
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

// Makro do alokowania pamięci dla tablicy.
// Wywołujemy funkcję reallocate z argumentami pointer, sizeof(type) * oldCount,
// sizeof(type) * newCount
#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
  (type *)reallocate(pointer, sizeof(type) * (oldCount),                       \
                     sizeof(type) * (newCount))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

// Makro do zwalniania pamięci dla tablicy.
// Wywołujemy funkcję reallocate z argumentami pointer, sizeof(type) * count, 0
#define FREE_ARRAY(type, pointer, count)                                       \
  reallocate(pointer, sizeof(type) * (count), 0)

void *reallocate(void *pointer, size_t oldSize, size_t newSize);
void freeObjects();
#endif
