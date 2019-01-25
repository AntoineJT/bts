#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Ce programme vérifie si un nombre est pair (+ s il est impair)\nNombre=");
    int n;
    scanf("%d",&n);
    if (n%2==0){
        printf("Le nombre %d est pair",n);
    } else {
        printf("Le nombre %d est impair",n);
    }
    return EXIT_SUCCESS;
}
