/*
	err.h
	written by Antoine James Tournepiche
	12/07/2018 10:50 - 12/11/2018 11:00
	LibUtil
*/

#ifndef _H_CATCHERR_
#define _H_CATCHERR_
#include "boolean.h"
/*
#if 0
typedef sbool bool_err;
#define b_err   -1
#endif
*/
typedef	enum {
	ERR_MEM_MALLOC=INT_MIN,
	ERR_MEM_REALLOC,
	
	ERR_UNLIKELY=-1,
	FALSE=0,
	TRUE=1
} bool_err;
/*
#if 0
extern bool err_has_failed(const bool_err b);
extern bool err_has_succeed(const bool_err b);
#endif
*/
extern void err_beep(void);
char* err_getmessage(const bool_err errcode);
#endif
