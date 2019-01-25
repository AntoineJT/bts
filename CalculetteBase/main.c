#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Ceci est une calculatrice en ligne de commandes\nEntrez 2 nombres\n");
    float n1,n2;
    scanf("%f",&n1);
    scanf("%f",&n2);
    printf("Tapez +, -, *, / ou | suivant le calcul que vous souhaitez effectuer\n");
    char c; // op
    fflush(stdin); // Flush the buffer to scanf correctly the c char
    scanf("%c",&c);
    float res=0;
    switch(c){ // %.3f because this is needed to fix (hide) the bug of arbitrary precision (maybe some buffer overwriting ?)
        case '+':
            printf("%.3f+%.3f=%.3f",n1,n2,n1+n2);
            break;
        case '-':
            printf("%.3f-%f.3=%.3f",n1,n2,n1-n2);
            break;
        case '*':
            printf("%.3f*%.3f=%.3f",n1,n2,n1*n2);
            break;
        case '/':
            if (n2!=0) // Check if different and not if equals to economize an instruction (in asm) : when the user has understand the program will throw him an error message, he will not divide by zero again (because it's useless) so it's more frequent that someone divide by something other than 0
                printf("%.3f/%.3f=%.3f",n1,n2,n1/n2);
            else
                fprintf(stderr,"Erreur : Division par 0 !"); // Prints out to stderr, which can be handle in batch for example and so output to a file (nameoftheprogram.exe 2>stderr.txt) (see test.bat file)
            break;
        case '|':
            if (n2>n1)
                res=n2-n1;
            else    if (n1>n2)
                        res=n1-n2;
            printf("|%.3f-%.3f|=%.3f",n1,n2,res);
            break;
        default:
            fprintf(stderr,"Erreur ! L'operation demandee n'existe pas !"); // Prints to stderr
    }
    /*
    if (c=='+')
        printf("%.3f+%.3f=%.3f",n1,n2,n1+n2);
    else    if (c=='-')
                printf("%.3f-%f.3=%.3f",n1,n2,n1-n2);
            else    if (c=='*')
                        printf("%.3f*%.3f=%.3f",n1,n2,n1*n2);
                    else    if (c=='/')
                                if (n2!=0) // Check if different and not if equals to economize an instruction (in asm) : when the user has understand the program will throw him an error message, he will not divide by zero again (because it's useless) so it's more frequent that someone divide by something other than 0
                                    printf("%.3f/%.3f=%.3f",n1,n2,n1/n2);
                                else
                                    fprintf(stderr,"Erreur : Division par 0 !"); // Prints out to stderr, which can be handle in batch for example and so output to a file (nameoftheprogram.exe 2>stderr.txt) (see test.bat file)
                            else
                                fprintf(stderr,"Erreur ! L'operation demandee n'existe pas !"); // Prints to stderr
    */
    return EXIT_SUCCESS;
}
