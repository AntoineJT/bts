#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef unsigned char boolean;
#define FALSE 0
#define TRUE 1

int main(void)
{
    SetConsoleOutputCP(1252);
    printf("Saisissez 10 nombres\n");
    int tab[10];
    unsigned int i;
    for(i=0;i<10;i++){
        printf("Nombre n°%u\n",i+1);
        scanf("%d",&tab[i]);
    }
    printf("Nombre à chercher : ");
    int n;
    scanf("%d",&n);
    boolean bIsInList=FALSE;
    for(i=0;i<10;i++){
        if(tab[i]==n){
            bIsInList=TRUE;
            break;
        }
    }
    if (bIsInList)
        printf("%d est dans la liste (Nombre n°%u)\n",n,i+1);
    else
        printf("%d n'est pas dans la liste\n",n);
    return EXIT_SUCCESS;
}
