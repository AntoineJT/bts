/*
	err.c
	written by Antoine James Tournepiche
	12/07/2018 10:52 - 12/11/2018 11:00
	LibUtil
*/

#include <stdio.h>
#include "boolean.h"
#include "err.h"

/* -----------------------------------  */
/*           ERROR CATCHING             */
/* -----------------------------------  */

/*
#if 0
inline bool err_has_failed(const sbool b){
    return (b==-1) ? true : false;
}

inline bool err_has_succeed(const sbool b){
    return (b==-1) ? false : true;
}
#endif
*/

/* -----------------------------------  */
/*              ERROR UTIL              */
/* -----------------------------------  */

inline void err_beep(void){
    putchar('\a');
}

/* -----------------------------------  */
/*           ERROR MESSAGES             */
/* -----------------------------------  */

char* err_getmessage(const bool_err errcode){
	switch(errcode){
		case ERR_MEM_MALLOC:
			return "MEMORY ALLOCATION ERROR!";
		case ERR_MEM_REALLOC:
			return "REALLOCATION ERROR!";
		
		case ERR_UNLIKELY:
			return "UNLIKELY ERROR!";
		case FALSE:
			return NULL;
		case TRUE:
			return NULL;
		default:
			return "UNKNOW ERROR!";
	}
}