/*
	memalloc.c
	written by Antoine James Tournepiche
	12/12/2018 20:24 - 12/12/2018 20:24
	LibUtil
*/

#include <stdlib.h>
#include "boolean.h"

bool mem_malloc(void* ptr,const size_t sz){
    ptr=malloc(sz);
    return (ptr!=NULL);
}

bool mem_malloc_mt(void* ptr,const size_t sz,unsigned int iter){ // mt -> multiple times
    ptr=(void*)NULL;
    while(iter!=0){
        ptr=malloc(sz);
        if(ptr!=NULL)
            return true;
        iter--;
    }
    return false;
}
