#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void str_set_lower(char* str){
    unsigned int len=strlen(str);
    char buff;
    for(register unsigned int i=0;i<len;i++){
        buff=*(str+i);
        if(buff>0x40&&buff<0x5B)
            *(str+i)+=0x20;
    }
}

int main(void)
{
    SetConsoleOutputCP(1252);
    puts("Ce programme affiche votre pr�nom (max. 20 caract�res) � l'envers");
    printf("Entrez votre pr�nom (max. 20 caract�res) : ");
    char name[20];
    scanf("%20s",name); // pas besoin de v�rifier si fonctionne
    unsigned char len=strlen(name);
    char rname[len];
    for(unsigned int i=0;i<len;i++)
        rname[i]=name[len-1-i];
    rname[len]='\0'; // terminate string
    str_set_lower(name);
    str_set_lower(rname);
    printf("Pr�nom � l'endroit : %s\nPr�nom � l'envers : %s\n",name,rname);
    return EXIT_SUCCESS;
}
