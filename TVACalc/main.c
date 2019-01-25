#include <stdio.h>
#include <stdlib.h>

#define TVA 0.2

#define TTC (1+TVA)

int main(void)
{
    printf("Ce programme va calculer le prix de la TTC d un produit a partir de son prix HT et vous afficher le total a payer en fonction du nombre de produits.\nPrix HT du produit ? ");
    float price;
    scanf("%f",&price);
    printf("Nombre de produit ? ");
    unsigned int num;
    scanf("%u",&num);
    printf("Prix TTC d un produit : %.2f\nPrix total TTC : %.2f",price*TTC,price*num*TTC);
    return EXIT_SUCCESS;
}
