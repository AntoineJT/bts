#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(1252);
    printf("Ce programme permet à l'utilisateur de taper une série d'entiers et ensuite d'indiquer le nombre d'entiers pairs et le nombre d'entiers impairs.\n");
    unsigned int pairs=0;
    unsigned int impairs=0;
    int entier;
    do {
        printf("Saisissez un entier (0 pour arrêter) : ");
        while(!scanf("%d",&entier))
            while(getchar()!='\n');
        if (entier^((entier>>1)<<1))
            impairs++;
        else
            pairs++;
    } while(entier!=0);
    printf("Pairs : %d\nImpairs : %d\n",pairs-1,impairs);
    return EXIT_SUCCESS;
}
