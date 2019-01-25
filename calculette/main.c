#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2;
    char inst;

    printf("Ceci est une mini calculatrice. Entrez les 2 nombres sur lesquels vous souhaitez realiser une somme ou un produit.\nNombres ? ");
    scanf("%d",&n1);
    scanf("%d",&n2);
    printf("Vous devez desormais selectionner l action que vous allez realiser : \n- s/S pour calculer la somme\n- p/P pour calculer le produit\n");
    fflush(stdin);
    scanf("%c",&inst);
    if (inst=='s'||inst=='S'){
        printf("%d+%d=%d",n1,n2,n1+n2);
    } else if (inst=='p'||inst=='P'){
        printf("%d*%d=%d",n1,n2,n1*n2);
    } else {
        printf("Une erreur s est produite : Vous n avez pas selectionner d actions a faire !");
    }
    return EXIT_SUCCESS;
}
