#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nb;
    unsigned char pos=0,nul=0,neg=0; // Valide puisque char n'est pas seulement utilisé pour désigner un caractère, mais également pour stocker un nombre sur un octet
    printf("Ce programme compte le nombre de nombres positifs, negatifs, ou nuls... On demande 5 fois un nombre a l utilisateur.\n1er Nombre ? ");
    scanf("%d",&nb);
    if (nb>0){ // Plus de chances que l'user tape un nombre positif (flemme de taper '-')
        pos++;
    } else if (nb<0){ // Plus de chances que l'user tape un nombre négatif que la valeur spécifique 0
        neg++;
    } else /*if (nb==0)*/ { // dernier cas
        nul++;
    }

    printf("2eme Nombre ? ");
    scanf("%d",&nb);// dernier cas
    if (nb>0){// dernier cas
        pos++;
    } else if (nb<0){
        neg++;
    } else /*if (nb==0)*/ {
        nul++;
    }

    printf("3eme Nombre ? ");
    scanf("%d",&nb);
    if (nb>0){
        pos++;
    } else if (nb<0){
        neg++;
    } else /*if (nb==0)*/ {
        nul++;
    }

    printf("4eme Nombre ? ");
    scanf("%d",&nb);
    if (nb>0){
        pos++;
    } else if (nb<0){
        neg++;
    } else /*if (nb==0)*/ {
        nul++;
    }

    printf("5eme Nombre ? ");
    scanf("%d",&nb);
    if (nb>0){
        pos++;
    } else if (nb<0){
        neg++;
    } else /*if (nb==0)*/ {
        nul++;
    }

    printf("Resultats :\nNombres positifs : %d\nNombres negatifs : %d\nNombres nuls : %d",(int)pos,(int)neg,(int)nul); // Caster utilise donc un peu plus de puissance lors de l'affichage des résultats mais permet d'économiser de la RAM via l'utilisation de char

    return EXIT_SUCCESS;
}
