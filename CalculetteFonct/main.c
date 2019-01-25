#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "boolean.h"
#include "calc.h"

int main(void)
{
    SetConsoleOutputCP(1252);
    puts("Ceci est une calculatrice en ligne de commandes");
    float n1;
    float n2;
    char c; // op
    do {
        boolean no_err=true;
        do {
            puts("Entrez un premier nombre");
            no_err=scanf("%f",&n1);
            if (!no_err){
                puts("Ceci n'est pas un nombre valide!");
                while(getchar()!='\n');
            }
        } while(!no_err);
        do {
            puts("Entrez un deuxième nombre");
            no_err=scanf("%f",&n2);
            if (!no_err){
                puts("Ceci n'est pas un nombre valide!");
                while(getchar()!='\n');
            }
        } while(!no_err);
        puts("Tapez +, -, *, / ou | suivant le calcul que vous souhaitez effectuer");
        while(getchar()!='\n'); // Flushing buffer
        scanf("%c",&c);
        float res=0;
        no_err=true;
        switch(c){ // %.3f because this is needed to fix (hide) the bug of arbitrary precision (maybe some buffer overwriting ?)
            case '+':
                res=calc_add(n1,n2);
                break;
            case '-':
                res=calc_sub(n1,n2);
                break;
            case '*':
                res=calc_mult(n1,n2);
                break;
            case '/':
                if (n2!=0) // Check if different and not if equals to economize an instruction (in asm) : when the user has understand the program will throw him an error message, he will not divide by zero again (because it's useless) so it's more frequent that someone divide by something other than 0
                    res=calc_div(n1,n2);
                else {
                    puts("Erreur : Division par 0 !");
                    no_err=false;
                }
                break;
            case '|':
                res=calc_abs(n1,n2);
                break;
            default:
                puts("Erreur ! L'opération demandée n'existe pas !");
                no_err=false;
                break;
        }
        if(no_err)
            printf("Résultat : %f%c%f=%f\n",n1,c,n2,res);
        do {
            while(getchar()!='\n');
            puts("Voulez-vous recommencer? [O/N]");
        } while(!scanf("%[OoNn]",&c));
    } while(c=='O'||c=='o');
    return EXIT_SUCCESS;
}
