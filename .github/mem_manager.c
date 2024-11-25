#include <stdlib.h>
#include <stdio.h>

#include "mem_manager.h"

#define MEM_SIZE 1000

typedef struct mem_block {
    void * data;
    struct mem_block * next;
} mem_block;

void * my_malloc(size_t size);
void my_free(void * ptr);
void * my_realloc(size_t nmemb, size_t size);