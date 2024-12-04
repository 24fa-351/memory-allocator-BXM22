#ifndef MEM_TEST_H
#define MEM_TEST_H

#include <stddef.h>

void * requestBlock(size_t size);
void * initialMemory(size_t size);
void * mem_malloc(size_t size);
void mem_free(void * ptr);
void * mem_realloc(size_t nmemb, size_t size);
void destroyHeap();



#endif 
