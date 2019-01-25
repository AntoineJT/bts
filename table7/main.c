#include <stdio.h>
#include <stdlib.h>

struct {
    unsigned int
        i : 4; // 0 to 15 : used value 1 to 11
} cpt; // compteur

int main(void)
{
    printf("Table de multiplication de 7\n");
    for (cpt.i=1;cpt.i<11;cpt.i++)
        printf("7 x %d = %d\n",cpt.i,cpt.i*7);
    return EXIT_SUCCESS;
}
