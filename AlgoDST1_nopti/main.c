#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Ce programme permet de calculer le salaire d'un chauffeur\nSaisir le salaire fixe : ");
    unsigned int fixe;
    scanf("%u",&fixe);
    printf("Saisir le Chiffre d'Affaires réel et le Chiffre d'Affaires Objectif\n");
    unsigned int car,cao;
    scanf("%u%u",&car,&cao);
    float prime;
    if (car>cao)
        prime=(car-cao)*0.02;
    else
        prime=0;
    printf("Saisir le nb de kms parcourus : ");
    unsigned int nbkm;
    scanf("%u",&nbkm);
    float indkm;
    if (nbkm<=600)
        indkm=nbkm*0.15;
    else    if (nbkm<=2000)
                indkm=600*0.15+(nbkm-600)*0.12;
            else
                indkm=600*0.15+1400*0.12+(nbkm-2000)*0.1;
    printf("Salaire : %.2f",fixe+prime+indkm);
    return EXIT_SUCCESS;
}
