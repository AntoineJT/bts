#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
/*#include <windows.h>

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
*/

int main(void)
{
    //color(10,0);
    printf("Ce programme calcule la somme des entiers de 1 a la limite que vous aurez specifiee.\n");
    uint32_t i=1;
    uint64_t sum=0;
    uint32_t lim;
    printf("Limite=");
    scanf("%" SCNu32,&lim);
    while(i<=lim){
        //printf("%" SCNu64 "+%" SCNu32 "=%" SCNu64 "\n",sum,i,sum+i);
        sum+=i;
        i++;
    }
    printf("Somme des entiers de 1 a %" SCNu32 "=%" SCNu64,lim,sum);
    return EXIT_SUCCESS;
}
