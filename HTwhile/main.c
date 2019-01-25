#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TVA 0.2

int main(void)
{
    SetConsoleOutputCP(1252);
    printf("Programme qui affiche un total TTC\n");
    char rep='v';
    float ttc=0;
    unsigned int cnt=1;
    float ht;
    unsigned int qt;
    while(rep!='f'){
        printf("Entrez le prix HT du produit N�%u, puis sa quantit�\n",cnt);
        scanf("%f%u",&ht,&qt); // this is not a protected scanf, and some stupid things can occurred if he inputs some strings
        ttc+=ht*qt;
        cnt++;
        printf("Autre produit (f pour fin) ? ");
        scanf(" %c",&rep); // the space before the format allows to remove the whitespace before the character entered by the user !
		while(getchar()!='\n'); // fflush(stdin) is evil ! never use it to clean an input buffer ! (or some undefined behavior will occurred) !
    }
    printf("Total TTC = %.2f",ttc*(1+TVA));
    return EXIT_SUCCESS;
}
