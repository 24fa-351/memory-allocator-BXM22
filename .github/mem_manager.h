#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <stddef.h>

void * requestBlock(size_t size);
void * initialMemory(size_t size);
void * mem_malloc(size_t size);
void mem_free(void * ptr);
void * mem_realloc(size_t nmemb, size_t size);
void destroyHeap();



#endif // MEM_MANAGER_H
