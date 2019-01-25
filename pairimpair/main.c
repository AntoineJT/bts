#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    printf("Ce programme permet a l utilisateur de taper une serie d entiers et ensuite de dire le nombre d entiers pairs et le nombre d entiers impairs.\n");
    uint8_t pairs=-1; // Comme compte 0 en pair donc commence à -1 (255 puis reboucle à partir de 0)
    uint8_t impairs=0;
    int entier;
    while(entier!=0){
        printf("Saisissez un entier (0 pour arreter) : ");
        scanf("%d",&entier);
        if (entier%2==0)
            pairs++;
        else
            impairs++;
    }
    printf("Pairs : %d\nImpairs : %d\n",pairs,impairs);
    return EXIT_SUCCESS;
}
