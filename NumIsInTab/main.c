#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Boolean defines
#define FALSE           0
#define TRUE            1

#define ISTABPREDEF     TRUE

int main(void)
{
    SetConsoleOutputCP(1252);
    #if !ISTABPREDEF
    printf("Saisissez 10 nombres\n");
    int tab[10];
    #else
    const int tab[10]={1,8,32,64,72,91,93,97,98,99};
    #endif
    unsigned int i;
    #if !ISTABPREDEF
    for(i=0;i<10;i++){
        printf("Nombre n°%u\n",i+1);
        scanf("%d",&tab[i]);
    }
    #endif
    printf("Nombre à chercher : ");
    int n;
    scanf("%d",&n);
    i=0;
    while(i<10&&tab[i]!=n)
        i++;
    if (i<10)
        printf("%d est dans la liste (Nombre n°%u)\n",n,i+1);
    else
        printf("%d n'est pas dans la liste\n",n);
    return EXIT_SUCCESS;
}
