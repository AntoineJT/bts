#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nbrV, nbrM;
    int prixV=250,prixM=120;
    printf("Ce programmme calcule la valeur totale d un troupeau\n");
    printf("Entrer le nb de vaches puis le nb de moutons\n");
    scanf("%d", &nbrV);
    scanf("%d", &nbrM);
    printf("La valeur totale du troupeau est %d euros\n",nbrV*prixV+nbrM*prixM);
    return 0;
}
