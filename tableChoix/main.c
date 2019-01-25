#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Ce programme permet d'afficher la table de multiplication du nombre de votre choix\n");
    unsigned int nb;
    char choice;
    do {
        printf("Table de multiplication de : ");
        scanf("%u",&nb);
        printf("\nTable de multiplication de %u\n",nb);
        for (unsigned int cnt=1;cnt<11;cnt++)
            printf("%u x %u = %u\n",nb,cnt,cnt*nb);
        do {
            printf("\nTapez 'n'/'N' pour quitter, ou 'o'/'O' pour continuer\nContinuer ? ");
            scanf(" %c",&choice); // " %c" allows to ignore whitespace before the input character
        } while(choice!='O'&&choice!='o'&&choice!='N'&&choice!='n');
    } while(choice!='N'&&choice!='n');
    return EXIT_SUCCESS;
}
