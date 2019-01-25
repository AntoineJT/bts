/*
	str_util.h
	written by Antoine James Tournepiche
	12/07/2018 09:14 - 12/11/2018 10:21
	LibUtil
*/

#ifndef _H_STR_UTIL_
#define _H_STR_UTIL_
#include <stdint.h>
#include "boolean.h"
#include "err.h"
#ifdef __MINGW64__
typedef uint64_t uint;
#elif defined(__MINGW32__)
typedef uint32_t uint;
#else // TODO Implement more compilation units
#error Compilation unit unimplemented!
#endif
char*       str_get_lower(const char* str);
void        str_set_lower(char* str);
char*       str_get_lower_at_pos(const char* str,uint pos);
//char*       str_get_lower_at_pos2(const char* str,uint pos);    // This seems to be just stupid shit!
void        str_set_lower_at_pos(char* str,uint pos);
//void        str_set_lower_at_pos2(char* str,uint pos);          // This seems to be just stupid shit!
char*       str_get_upper(const char* str);
void        str_set_upper(char* str);
char*       str_get_upper_at_pos(const char* str,uint pos);
//char*       str_get_upper_at_pos2(const char* str,uint pos);    // This seems to be just stupid shit!
void        str_set_upper_at_pos(char* str,uint pos);
//void        str_set_upper_at_pos2(char* str,uint pos);          // This seems to be just stupid shit!
char*       str_get_reverse(const char* str);
bool        str_set_reverse(char* str);
bool_err    str_startswith(const char* starts,const char* str);
bool_err    str_endswith(const char* ends,const char* str);
bool_err    str_endswith2(const char* ends,const char* str);
bool        str_endswith3(const char* ends,char* str);
#endif
