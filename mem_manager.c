#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h>

#include "mem_manager.h"


typedef struct mem_block {
    size_t size;
    int data;
    struct mem_block * next;
} mem_block;

#define BLOCK_SIZE sizeof(mem_block)

static void* heap_start = NULL;
static mem_block* free_list = NULL;
static pthread_mutex_t heap_lock = PTHREAD_MUTEX_INITIALIZER;

void * requestBlock(size_t size){
    mem_block * block = free_list;
    mem_block * prev = NULL;
    while(block != NULL){
        if(block->size >= size){
            if(prev != NULL){
                prev->next = block->next;
            }else{
                free_list = block->next;
            }
            return block;
        }
        prev = block;
        block = block->next;
    }
    return NULL;
}

void * initialMemory(size_t size){
    void * ptr = sbrk(size);
    if(ptr == (void *) -1){
        return NULL;
    }
    return ptr;
}

void * mem_malloc(size_t size){
    if(size == 0){
        return NULL;
    }
    pthread_mutex_lock(&heap_lock);

    mem_block * block = requestBlock(size);
    if(!heap_start){
        heap_start = sbrk(size + BLOCK_SIZE);
    }
    pthread_mutex_unlock(&heap_lock);

}

void mem_free(void * ptr){
    if(ptr == NULL){
        return;
    }
    pthread_mutex_lock(&heap_lock);
    mem_block * block = (mem_block *) ptr;
    block->next = free_list;
    free_list = block;
    pthread_mutex_unlock(&heap_lock);
}

void * mem_realloc(size_t nmemb, size_t size){
    if(size == 0){
        return NULL;
    }
    pthread_mutex_lock(&heap_lock);
    mem_block * block = requestBlock(size);
    if(!heap_start){
        heap_start = sbrk(size + BLOCK_SIZE);
    }
    pthread_mutex_unlock(&heap_lock);
    return block;
}

void destroyHeap(){
    pthread_mutex_lock(&heap_lock);
    heap_start = NULL;
    free_list = NULL;
    pthread_mutex_unlock(&heap_lock);
}