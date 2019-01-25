#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

float val_max(float v1,float v2);

int main(void)
{
    SetConsoleOutputCP(1252);
    puts("Ce programme renvoie la valeur maximale entre deux valeurs saisies\nSaisissez 2 réels");
    float val1;
    float val2;
    scanf("%f%f",&val1,&val2);
    printf("La plus grande valeur est : %f",val_max(val1,val2));
    return EXIT_SUCCESS;
}

float val_max(float v1,float v2){
    if(v1>v2)
        return v1;
    return v2; // if v2>v1 or v2==v1 this is working
}
