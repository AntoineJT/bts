#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(1252);
    printf("Ce programme permet de calculer le salaire d'un chauffeur\nSaisir le salaire fixe : ");
    float fixe;
    scanf("%f",&fixe);
    printf("Saisir le Chiffre d'Affaires réel et le Chiffre d'Affaires Objectif\n");
    unsigned int car,cao;
    scanf("%u%u",&car,&cao);
    if (car>cao)
        fixe+=(car-cao)*0.02;
    printf("Saisir le nb de kms parcourus : ");
    unsigned int nbkm;
    scanf("%u",&nbkm);
    if (nbkm<=600)
        fixe+=nbkm*0.15;
    else    if (nbkm<=2000)
                fixe+=600*0.15+(nbkm-600)*0.12;
            else
                fixe+=600*0.15+1400*0.12+(nbkm-2000)*0.1;
    printf("Salaire : %.2f",fixe);
    return EXIT_SUCCESS;
}
