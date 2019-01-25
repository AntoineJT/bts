#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define INPUT(_PTR_) \
    do { \
        valid=scanf("%d",_PTR_); \
        if (!valid){ \
            while(getchar()!='\n'); \
            puts("\aValeur invalide! Veuillez renseigner de nouveau une valeur!"); \
        } \
    } while(!valid);

int main(void)
{
    SetConsoleOutputCP(1252);
    puts("Ce programme retourne la plus grande valeur d'une suite d'entiers renseignée par l'utilisateur\nSaisir un entier (0 pour arrêter)");
    unsigned int i=0;
    int max;
    unsigned int valid;
    INPUT(&max);
    if (max==0)
        puts("Vous n'avez renseigné aucune valeur!");
    else {
        int val=max;
        while(val!=0){
            i++;
            if(val>max)
                max=val;
            puts("Saisir un entier (0 pour arrêter)");
            INPUT(&val);
        }
        printf("Maximum : %d\nNombre d'entiers saisis : %u\n",max,i);
    }
    return EXIT_SUCCESS;
}
