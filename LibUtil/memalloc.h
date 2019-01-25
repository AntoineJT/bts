/*
	memalloc.h
	written by Antoine James Tournepiche
	12/12/2018 20:24 - 12/12/2018 20:24
	LibUtil
*/

#ifndef _H_MEMALLOC_
#define _H_MEMALLOC_
#include "boolean.h"
bool mem_malloc(void* ptr,const size_t sz);
bool mem_malloc_mt(void* ptr,const size_t sz,unsigned int iter);
#endif
