#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Boolean defines
#define FALSE           0
#define TRUE            1

// Conditional defines
#define ISTABPREDEF     TRUE
#define LISTOCC         TRUE

int main(void)
{
    SetConsoleOutputCP(1252);
    printf("Ce programme compte le nombre d'occurences dans un tableau\n");
    #if !ISTABPREDEF
    printf("Saisissez 20 nombres\n");
    float tab[20];
    for (unsigned int i=0;i<20;i++){
        printf("Nombre n°%u\n",i+1);
        while(!scanf("%f",&tab[i]))
            while(getchar()!='\n');
    }
    #else
    const float tab[20]={1.5,2,3,4,5,7.2,8,9,5,4,1,2,5,50,50,50,48,96,75,50};
    #endif
    printf("Nombre à chercher : ");
    float search;
    while(!scanf("%f",&search))
        while(getchar()!='\n');
    unsigned int occ=0;
    #if LISTOCC
    unsigned int ind[20];
    #endif
    for (unsigned int i=0;i<20;i++)
        if (tab[i]==search){
            #if LISTOCC
            ind[occ]=i;
            #endif
            occ++;
        }
    printf("Nombre d'occurences de %f = %u\n",search,occ);
    #if LISTOCC
    printf("Indice des occurences : \n");
    for(unsigned int i=0;i<occ;i++)
        printf("-> %d\n",ind[i]);
    #endif
    return EXIT_SUCCESS;
}
