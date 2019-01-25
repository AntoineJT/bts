#include <stdio.h>
#include <stdlib.h>
#define COW_PRICE 250
#define SHEEP_PRICE 120

int main(void)
{
    printf("Ce programme calcule le prix total de votre troupeau de vaches et de moutons.\nCombien de vaches avez-vous ? ");
    int ncow,nsheep;
    scanf("%d",&ncow);
    printf("Combien de moutons avez-vous ? ");
    scanf("%d",&nsheep);
    printf("Votre troupeau vous coute donc %d euros.",ncow*COW_PRICE+nsheep*SHEEP_PRICE);
    return EXIT_SUCCESS;
}
