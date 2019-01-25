/*
	test/maintest.c
	written by Antoine James Tournepiche
	12/07/2018 11:03 - 12/07/2018 12:03
	LibUtil

	Testing file : useless at all except for me
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../err.h"
#include "../str_util.h"
#include "../boolean.h"
#include "../memalloc.h"

#ifdef __WIN32
#include <windows.h>
#endif

int main(void){
    #ifdef __WIN32
    SetConsoleOutputCP(1252);
    #endif
    #define STR "Squalala!!"
    char str[]=STR;
    strcpy(str,STR);
    puts("Chaîne de base : " STR);
    printf("Inversion complète : %u\nTest : %s\n",(unsigned int)str_set_reverse(str),str);
    strcpy(str,STR);
    str_set_lower(str);
    printf("Chaîne en minuscules : %s\n",str);
    str_set_upper(str);
    printf("Chaîne en majuscules : %s\n",str);
    printf("Err has succeed : %u\n",err_has_succeed((sbool)0));
    //printf("%s commence par %s : %u","Bonjour, je suis quelqu'un","Bonjour",(unsigned int)str_startswith("Bonjour","Bonjour, je suis quelqu'un"));
    printf("%u",(unsigned int)str_endswith3("!!","test!!"));
    err_beep();
    char* squalala=malloc(8*sizeof(char));
    squalala="Squalala";
    if(mem_malloc(squalala,10*sizeof(char)))
        squalala="Squalala!!";
    printf("squalala=%s\n",squalala);
    unsigned int iter=1;
    while(iter!=0){
        mem_malloc(squalala,10*sizeof(char));
        iter++;
    }
    while(getchar()!='\n'); // wait for input
    return EXIT_SUCCESS;
    #undef STR
}
