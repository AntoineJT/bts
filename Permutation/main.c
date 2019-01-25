#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void permut(int a,int b) // Passage par valeur
{
    int c;
    c=a;
    a=b;
    b=c;
}

void permut_ptr(int* a,int* b) // Passage par référence
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

int main(void)
{
    SetConsoleOutputCP(1252);
    puts("Ce programme permute le contenu de deux variables\nSaisissez 2 entiers");
    int a;
    int b;
    scanf("%d%d",&a,&b);
    printf("Avant permutation\na=%d et b=%d\n",a,b);
    permut(a,b);
    printf("Après permutation (passage par valeur)\na=%d et b=%d\n",a,b);
    permut_ptr(&a,&b);
    printf("Après permutation (passage par référence)\na=%d et b=%d\n",a,b);
    return EXIT_SUCCESS;
}
