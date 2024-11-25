#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <stddef.h>

void * my_malloc(size_t size);
void my_free(void * ptr);
void * my_realloc(size_t nmemb, size_t size);


#endif // MEM_MANAGER_H
