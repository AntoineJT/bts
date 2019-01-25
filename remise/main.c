#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Ce programme vous offre une reduction de 1 pourcent pour un achat d une valeur superieure a 800 euros!\nMontant=");
    float price;
    scanf("%f",&price);
    if (price>800){
        price*=0.99;
    }
    printf("Vous devez payer %.2f euros!",price);
    return EXIT_SUCCESS;
}
