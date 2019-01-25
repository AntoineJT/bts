#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    printf("Ce programme calcule la somme des entiers de 1 a 100.\n");
    uint8_t i=1;
    uint16_t sum=0;
    while(i<101){
        //printf("%d+%d=%d\n",sum,i,sum+i);
        sum+=i;
        i++;
    }
    printf("Somme des entiers de 1 a 100=%d",sum);
    return EXIT_SUCCESS;
}
