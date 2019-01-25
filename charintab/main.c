#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#ifndef __cplusplus
typedef unsigned char bool;
#define true    1
#define false   0
#endif

bool str_contains(const char* str,const char c){
    unsigned long long len=strlen(str);
    register unsigned long long i=0;
    do
        i++;
    while(*(str+i)!=c);
    return(i<len);
}

int main(void)
{
    SetConsoleOutputCP(1252);
    const char tab[]="Ceci est un tableau de caractères du pif!";
    printf("Caractère à chercher : ");
    char c;
    scanf("%c",&c);
    bool isIn=str_contains(tab,c);
    if(isIn)
        printf("'%c' est dans la liste\n",c);
    else
        printf("'%c' n'est pas dans la liste\n",c);
    return EXIT_SUCCESS;
}
