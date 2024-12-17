#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>

#include "mem_manager.h"


int main(int argc, char *argv[]) {
    printf("Requesting memory block...\n");
    void * block = requestBlock(10);
    if(block == NULL){
        printf("Memory block request failed\n");
    }else{
        printf("Memory block request successful\n");
    }
    printf("Testing memory allocation...\n");
    void * ptr = mem_malloc(10);
    if(ptr == NULL){
        printf("Memory allocation failed\n");
    }else{
        printf("Memory allocation successful\n");
    }

   
    

    return 0;
}