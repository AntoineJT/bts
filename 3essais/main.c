#include <stdio.h>
#include <stdlib.h>
/*
Version sans boolean

#include <stdint.h>

int main(void)
{
    printf("Bienvenue dans le jeu des 3 essais : Vous devez trouver le caractere gagnant en 3 essais.\n");
    uint8_t i=0;
    char c;
    while(i<=3){
        if (c=='0'){
            printf("Vous avez gagne au bout de l essai numero %d !",i);
            break;
        }
        printf("Saisissez un caractere : ");
        fflush(stdin);
        scanf("%c",&c);
        i++;
    }
    if (c!='0')
        printf("Vous avez perdu !");
    return EXIT_SUCCESS;
}
*/

/* Version avec boolean */

struct {
    unsigned int
        i : 2,
        boolean : 1;
} data;

int main(void)
{
    printf("Bienvenue dans le jeu des 3 essais : Vous devez trouver le caractere gagnant en 3 essais.\n");
    data.i=0;
    char c;
    while(data.i<3&&!data.boolean){
        if (c=='0')
            data.boolean=1;
        else {
            printf("Il vous reste %d essais.\nSaisissez un caractere : ",3-data.i);
            fflush(stdin);
            scanf("%c",&c);
            data.i++;
        }
    }
    if (c!='0')
        printf("Vous avez perdu !");
    else
        printf("Vous avez gagne au bout de l essai numero %d !",data.i);
    return EXIT_SUCCESS;
}
