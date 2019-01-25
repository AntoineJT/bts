#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <limits.h>

// Boolean defines
#define FALSE           0
#define TRUE            1

#define ISTABPREDEF     FALSE

int main(void)
{
    SetConsoleOutputCP(1252);
    printf("Ce programme cherche la valeur maximale contenue dans un tableau et son indice\n");
    #if !ISTABPREDEF
    printf("Saisissez 10 nombres\n");
    int tab[10];
    #else
    const int tab[10]={1,8,32,64,72,91,93,97,98,99};
    #endif
    unsigned int i;
    #if !ISTABPREDEF
    for(i=0;i<10;i++){
        printf("Nombre n°%u\n",i+1);
        scanf("%d",&tab[i]);
    }
    #endif
    unsigned int n=0;
    //const int int_min=-(((unsigned int)-1)>>1)-1; // hack method to get INT_MIN value without limits.h
    int val=tab[0];
    for (i=0;i<10;i++)
        if (tab[i]>val){
            n=i;
            val=tab[i];
        }
    printf("Le maximum est : %d à la position %u",val,n);
    return EXIT_SUCCESS;
}
