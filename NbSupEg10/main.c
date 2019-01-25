#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define     FALSE           0
#define     TRUE            1

#define     ISTABPREDEF     FALSE

int main(void)
{
    SetConsoleOutputCP(1252);
    #if ISTABPREDEF
    const int tab[10]={5,7,8,65,12,74,65,95,10,25};
    #else
    int tab[10];
    printf("Saisissez 10 nombres\n");
    #endif
    unsigned int n=0;
    for (unsigned int i=0;i<10;i++){
        #if !ISTABPREDEF
        printf("Nombre n°%u : ",i+1);
        while(!scanf("%d",&tab[i])){
            while(getchar()!='\n'); // flush stdin
            printf("Erreur! Veuillez réécrire le nombre n°%u\n",i+1);
        }
        #endif
        if(tab[i]>=10)
            n++;
    }
    printf("Il y a %u nombres supérieurs ou égal à 10",n);
    return EXIT_SUCCESS;
}
