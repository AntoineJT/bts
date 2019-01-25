/*
	str_util.c
	written by Antoine James Tournepiche
	12/07/2018 09:14 - 12/11/2018 10:21
	LibUtil

	This file is used to manipulate strings
*/

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "boolean.h"
#include "err.h"
#include "str_util.h"

/* -----------------------------------  */
/*              LOWERCASE               */
/* -----------------------------------  */

char* str_get_lower(const char* str){
    uint len=strlen(str);
    char* lower=malloc((len-1)*sizeof(char));
    strcpy(lower,str);
    register char buff; // check if faster than without register keyword
    for(register uint i=0;i<len;i++){
        buff=*(lower+i);
        if(buff>0x40&&buff<0x5B)
            *(lower+i)+=0x20;
    }
    return lower;
}

void str_set_lower(char* str){
    uint len=strlen(str);
    register char buff; // check if faster than without register keyword
    for(register uint i=0;i<len;i++){
        buff=*(str+i);
        if(buff>0x40&&buff<0x5B)
            *(str+i)+=0x20;
    }
}

char* str_get_lower_at_pos(const char* str,uint pos){
    char* lower=malloc((strlen(str)-1)*sizeof(char));
	if(lower!=NULL){
		strcpy(lower,str);
		char buff=*(lower+pos);
		if(buff>0x40&&buff<0x5B)
			*(lower+pos)+=0x20;
	}
	return lower;
}

/*
#if 0
char* str_get_lower_at_pos2(const char* str,uint pos){
    char* lower=malloc((strlen(str)-1)*sizeof(char));
    strcpy(lower,str);
    char buff=*(lower+pos);
    if(buff<0x41||buff>0x5A)
        return lower;
    *(lower+pos)+=0x20;
    return lower;
}
#endif
*/

void str_set_lower_at_pos(char* str,uint pos){
    char buff=*(str+pos);
    if(buff>0x40&&buff<0x5B)
        *(str+pos)+=0x20;
}

/*
#if 0
void str_set_lower_at_pos2(char* str,uint pos){
    char buff=*(str+pos);
    if(buff<0x41||buff>0x5A)
        return;
    *(str+pos)+=0x20;
}
#endif
*/

/* -----------------------------------  */
/*              UPPERCASE               */
/* -----------------------------------  */

char* str_get_upper(const char* str){
    uint len=strlen(str);
    char* upper=malloc((len-1)*sizeof(char));
	if(upper!=NULL){
		strcpy(upper,str);
		register char buff; // check if faster than without register keyword
		for(register uint i=0;i<len;i++){
			buff=*(upper+i);
			if(buff>0x60&&buff<0x7B)
				*(upper+i)-=0x20;
		}
	}
    return upper;
}

void str_set_upper(char* str){
    uint len=strlen(str);
    register char buff; // check if faster than without register keyword
    for(register uint i=0;i<len;i++){
        buff=*(str+i);
        if(buff>0x60&&buff<0x7B)
            *(str+i)-=0x20;
    }
}

char* str_get_upper_at_pos(const char* str,uint pos){
    char* upper=malloc((strlen(str)-1)*sizeof(char));
	if(upper!=NULL){
		strcpy(upper,str);
		char buff=*(upper+pos);
		if(buff>0x60&&buff<0x7B)
			*(upper+pos)-=0x20;
	}
    return upper;
}

/*
#if 0
char* str_get_upper_at_pos2(const char* str,uint pos){
    char* upper=malloc((strlen(str)-1)*sizeof(char));
    strcpy(upper,str);
    char buff=*(upper+pos);
    if(buff<0x61||buff>0x7A)
        return upper;
    *(upper+pos)-=0x20;
    return upper;
}
#endif
*/

void str_set_upper_at_pos(char* str,uint pos){
    char buff=*(str+pos);
    if(buff>0x60&&buff<0x7B)
        *(str+pos)-=0x20;
}

/*
#if 0
void str_set_upper_at_pos2(char* str,uint pos){
    char buff=*(str+pos);
    if(buff<0x61||buff>0x7A)
        return;
    *(str+pos)-=0x20;
}
#endif
*/

/* -----------------------------------  */
/*              REVERSION               */
/* -----------------------------------  */

char* str_get_reverse(const char* str){
    uint len=strlen(str);
    char* rstr=malloc((len-1)*sizeof(char));
    if(rstr==NULL)
        return NULL;
    for(register uint i=0;i<len;i++)
        *(rstr+i)=*(str+(len-1-i));
    *(rstr+len)='\0'; // terminate string
    return rstr;
}

bool str_set_reverse(char* str){ // TODO to try
    uint len=strlen(str);
    char* rstr=malloc((len-1)*sizeof(char));
    if(rstr==NULL)
        return false; // error
    for(register uint i=0;i<len;i++)
        *(rstr+i)=*(str+(len-1-i));
    *(rstr+len)='\0'; // terminate string
    strcpy(str,rstr);
    *(str+len)='\0';
    return true;
}

/* -----------------------------------  */
/*                REGEX                 */
/* -----------------------------------  */

bool_err str_startswith(const char* starts,const char* str){
    uint slen=strlen(starts);
    if(slen>strlen(str))
        return b_err;
    char* str2=malloc((slen-1)*sizeof(char));
    if (str2==NULL)
        return b_err;
    strncpy(str2,str,slen);
    *(str2+slen)='\0';
    return !strcmp(starts,str2);
}

// First version
bool_err str_endswith(const char* ends,const char* str){ // TODO To improve
    uint elen=strlen(ends);
    if(elen>strlen(str))
        return false;
    char* rstr=str_get_reverse(str);
    if(rstr==NULL)
        return b_err;
    char* str2=malloc((elen-1)*sizeof(char));
    if(str2==NULL)
        return b_err;
    strncpy(str2,rstr,elen);
    *(str2+elen)='\0';
    free(rstr);
    if(!str_set_reverse(str2))
        return b_err;
    return !strcmp(ends,str2);
}

//  Better version ?? (Need to bench that vs the first one)
bool_err str_endswith2(const char* ends,const char* str){ // TODO To improve
    uint slen=strlen(str);
    uint elen=strlen(ends);
    if(elen>slen)
        return false;
    uint pos=slen-elen;
    if(pos==0)
        return !strcmp(ends,str);
    char* ptr=malloc((slen-1)*sizeof(char));
    if(ptr==NULL)
        return b_err;
    strcpy(ptr,str);
    ptr+=pos;
    bool equal=!strcmp(ends,ptr);
    ptr-=pos;
    free(ptr); // Need to check if it has some memory leaks!
    return equal;
}

// Better version than the 2nd one (Need to bench!)
bool str_endswith3(const char* ends,char* str){
    uint slen=strlen(str);
    uint elen=strlen(ends);
    if(elen>slen)
        return false;
    uint pos=slen-elen;
    if(pos==0)
        return !strcmp(ends,str);
    str+=pos;
    bool equal=!strcmp(ends,str);
    str-=pos;
    return equal;
}

